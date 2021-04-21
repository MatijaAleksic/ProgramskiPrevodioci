%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  
  int var_num = 0;
  int param_num = 0;
  
  int fun_idx = -1;
  int fcall_idx = -1;
  
  int tip = -1;
  int return_exists = -1;
  
  int bloc_idx = -1;
  int bloc_vars = 0;
  int bloc_active = 0;
  
  int for_indx = -1;
  
  int fun_call_params = 0;
  int fun_call_params_check_type=0;
  
  int check_tip = -1;

%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP

%token _COMMA
%token _INCREMENT
%token _WHILE
%token _FOR
%token _DOTDOT

%token _AND
%token _OR

%token _CHECK 
%token _CASE 
%token _ARROW
%token _BREAK
%token _OTHERWISE

%type <i> num_exp exp literal function_call argument rel_exp

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
			print_symtab();
       }
	   
  ;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);
      }
    _LPAREN parameter_list _RPAREN body
      {
        //clear_symbols(fun_idx + 1);
        var_num = 0;
		param_num = 0;
		
      }
  ;
  

parameter_list
  : /* empty */
      { set_atr1(fun_idx, 0); }
  | parameters
  ;

parameters
  : _TYPE _ID
      {
		if($1 == VOID)
			err("cannot assign void to parameter");
		
		
		insert_symbol($2, PAR, $1, ++param_num, fun_idx	);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, $1);
      }
  | parameters _COMMA _TYPE _ID
	  {
		  if($3 == VOID)
			err("cannot assign void to parameter");
		
		
		insert_symbol($4, PAR, $3, ++param_num, fun_idx);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, $3);
	  }
  ;
  ;
  
body
  : _LBRACKET 
	  {
		  return_exists = -1;
	  }
	variable_list statement_list _RBRACKET
	  {
		if(get_type(fun_idx) == INT || get_type(fun_idx) == UINT)
		{
			if(return_exists == -1)
			warning("Function should return something!");
		}
	  }
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE
  {
	  if($1 == VOID)
		err("Cannot assign void to variable");
	  tip = $1;
  }
  vars _SEMICOLON
  ;
  
 vars
  : _ID
	  {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol($1, VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol($1, VAR, tip , ++var_num, fun_idx);
			else
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", $1);
				else
					insert_symbol($1, VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol($1, VAR, tip , ++bloc_vars, fun_idx);
	    }
      }
  | vars _COMMA _ID
	{
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol($3, VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol($3, VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", $3 );
				else
					insert_symbol($3, VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol($3, VAR, tip , ++bloc_vars, fun_idx);
	    }
      }
  | _ID _ASSIGN literal
	  {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol($1, VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol($1, VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", $1);
				else
					insert_symbol($1, VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol($1, VAR, tip , ++bloc_vars, fun_idx);
	    }
		
		if(get_type(lookup_symbol($1, VAR|PAR)) != get_type($3))
			err("variable and literal are not of the same type");
      }
  | vars _COMMA _ID _ASSIGN literal
	  {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol($3, VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol($3, VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", $3);
				else
					insert_symbol($3, VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol($3, VAR, tip , ++bloc_vars, fun_idx);
	    }
		
		if(get_type(lookup_symbol($3, VAR|PAR)) != get_type($5))
			err("variable and literal are not of the same type");
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | while_statement
  |{for_indx = get_last_element() + 1;} for_statement
  | function_call _SEMICOLON
  | check_statement
  | increment
  ;
  
  
increment
  : _ID _INCREMENT _SEMICOLON
	{
	  if(lookup_symbol($1, VAR|PAR) == NO_INDEX)
		err("Not defined:'%s'", $1 );
	}
  ;
  
  
check_statement
  : _CHECK _LPAREN check_expression _RPAREN
	_LBRACKET cases otherwise _RBRACKET
  ;
  
check_expression
  : _ID
	  {
		  int id_indx = lookup_symbol($1, VAR|PAR);
		  if(id_indx == NO_INDEX)
			   err("'%s' must be defined", $1);
		   
		  check_tip = get_type(id_indx);
	  }
  ;
	
cases
  : case_statement
  | cases case_statement
  ;
  
case_statement
  : _CASE literal
  {  
	  if(check_tip != get_type($2))
			err("Case type and literal are not of the same type");
  }
  _ARROW case_body
  ;

  
case_body
  : statement
  | statement _BREAK _SEMICOLON
  ;
  
otherwise
  : _OTHERWISE _ARROW statement
  | _OTHERWISE _ARROW statement _BREAK _SEMICOLON
  ;
  
for_statement
  :
  _FOR _LPAREN _TYPE _ID _ASSIGN literal _DOTDOT literal _RPAREN
  {
	  if(lookup_symbol($4, VAR|PAR) == NO_INDEX)
		insert_symbol($4, VAR, $3 , NO_ATR, NO_ATR);
	  else
	  {
		err("redefinition of '%s'", $4);
		insert_symbol($4, VAR, $3 , NO_ATR, NO_ATR);
	  }
		   
	  if($3 != get_type($6) || $3 != get_type($8))
	  {
		  err("Incopatable types in for loop");
	  }
  }  
  statement
  {
	  
	  /*print_symtab();
	  printf("%d", for_indx);*/
	  
	  clear_symbols(for_indx);
	  for_indx = -1;
	  //clear_symbols(for_indx);
	  /*print_symtab();*/
  }
  ;
  
while_statement
  : _WHILE _LPAREN rel_expresions _RPAREN statement
  ;

compound_statement
  : _LBRACKET 
	  {
		bloc_active = 1;
		bloc_idx = get_last_element() + 1;
		bloc_vars = 0;
	  }
    variable_list statement_list _RBRACKET
	  {
		bloc_active = 0;
		bloc_idx = get_last_element() - bloc_vars;
		clear_symbols(bloc_idx);
		/*print_symtab();
		clear_symbols(bloc_idx);
		print_symtab();*/
	  }
  ;
  

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
      }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | _ID _INCREMENT
	  {
		$$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
	  }
  | function_call
	 {
		 $$  = $1;
	 }
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;
  

literal
  : _INT_NUMBER
      { 
		$$ = insert_literal($1, INT);
	  }

  | _UINT_NUMBER
      { 
		$$ = insert_literal($1, UINT);
	  }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
	    fun_call_params = 0;
		fun_call_params_check_type = fcall_idx + 1;
      }
    _LPAREN arguments _RPAREN
      {
        if(get_atr1(fcall_idx) != fun_call_params)
          err("wrong number of args to function '%s'",get_name(fcall_idx));
        $$ = fcall_idx;
      }
  ;

arguments
  : argument
  | arguments _COMMA argument
  ;
  
argument
  : /* empty */ {}
  | _ID
	{ 
		$$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
		
		int id_idx = lookup_symbol($1, VAR|PAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
	}
	
  | literal
	{
		if(get_type(fun_call_params_check_type) != get_type($1))
			err("Type of parameter '%d' not valid", fun_call_params);
		fun_call_params_check_type++;
		fun_call_params++;
	}
  | _ID _INCREMENT
	  {
		$$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
	  
		int id_idx = lookup_symbol($1, VAR|PAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
	  }
  ;

if_statement
  : if_part %prec ONLY_IF
  | if_part _ELSE statement
  ;

if_part
  : _IF _LPAREN rel_expresions _RPAREN statement
  ;
  
rel_expresions
  : rel_exp
  | rel_expresions _OR rel_exp
  | rel_expresions _AND rel_exp
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
		return_exists = 1;
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
      }
	| _RETURN _SEMICOLON
	  {
		  return_exists = 1;
		if(get_type(fun_idx) == INT || get_type(fun_idx) == UINT)
          warning("Function should return the specified type!");
	  }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}

