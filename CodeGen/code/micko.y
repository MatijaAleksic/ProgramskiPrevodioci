%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  
  int argument_type_check= -1;
  int param_num = 0;

  int tip = -1;
  int return_exists = -1;
  
  int bloc_idx = -1;
  int bloc_vars = 0;
  int bloc_active = 0;
  
  int for_active = -1;
  int for_indx = -1;
  int lit1 = 999;
  int lit2 = 998;
  
  int fun_call_params = 0;
  int fun_call_params_check_type=0;
  int for_exit_num = -1;
  
  int check_tip = -1;
  
  int condif_mov_idx = -1;
  int condif_active = 0;
  
  int while_active = 0;
  int while_cmp = -1;
  int while_stat = -1;
  int while_exit_num = -1;
  
  int lab_num_backup = -1;
  int check_cmp_num = -1;
  int check_exit_num = -1;
  int otherwise_exits = -1;
  
  int increment_list[10]={0,0,0,0,0,0,0,0,0,0};
  
  int var_assign_indx_list[10]={0,0,0,0,0,0,0,0,0,0};
  int literal_assign_list[10]={0,0,0,0,0,0,0,0,0,0};
  
  int check_idx = -1;
  int check_cmp[20]={-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99};
  
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
%token _QUESTION
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

%type <i> num_exp exp literal rel_expresions arguments conditional_exp
%type <i> function_call argument rel_exp if_part

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : global_list  function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
			//print_symtab();
       }
	   
  ;
  
global_list
	: /*empty*/
	| global_list global_var
	 /*{
		print_symtab();
     } */	
	;

global_var
	: _TYPE _ID _SEMICOLON
	{
		int idx = lookup_symbol($2, GVAR); 
		if (idx != NO_INDEX) 
		{
				err("redefinition of '%s'", $2);
		} else {
			insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR);
			code("\n%s:\n\t\tWORD\t1", $2);
		}
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
	  
	    code("\n%s:", $2);
		code("\n\t\tPUSH\t%%14");
		code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter_list _RPAREN body
      {
        //clear_symbols(fun_idx + 1);
        var_num = 0;
		param_num = 0;
		
		code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
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
	variable_list
	  {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
		
		for(int i=0;i< 10;i++){ 
			if(var_assign_indx_list[i] != 0){
				gen_mov(literal_assign_list[i],var_assign_indx_list[i]);
		  }
		  var_assign_indx_list[i] = 0;
		  literal_assign_list[i] = 0;
		}
      }
	  
	statement_list _RBRACKET
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
		
		int id_index = lookup_symbol($1, VAR|PAR);
		if(id_index == NO_INDEX)
		{
			err("Not defined %s", $1);
		}


		for(int i=0;i< 10;i++){ 
			if(var_assign_indx_list[i] == 0){
				var_assign_indx_list[i] = id_index;
				literal_assign_list[i] = $3;
				break;
		  }
		}
		//gen_mov($3, id_index);
		
		
		
		
		
		
		
		
		
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
		
		
		int id_index = lookup_symbol($3, VAR|PAR);
		if(id_index == NO_INDEX)
		{
			err("Not defined %s", $3);
		}
		
		gen_mov($5, id_index);
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
	  int inc_idx = lookup_symbol($1, VAR|PAR|GVAR);
	  if(inc_idx == NO_INDEX)
		err("Not defined:'%s'", $1 );
	
	  code("\n\t\tADDS\t");
	  gen_sym_name(inc_idx);
	  code(",$1,");
	  gen_sym_name(inc_idx);
	}
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
  : _ID _ASSIGN
	{
		condif_active = 0;
		condif_mov_idx = lookup_symbol($1, VAR|PAR|GVAR);
	}
	num_exp _SEMICOLON
      {
		int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($4))
            err("incompatible types in assignment");
		
		
		for(int i=0;i< 10;i++){ 
			if(increment_list[i] != 0){
				
				code("\n\t\tADDS\t");
				gen_sym_name(increment_list[i]);
				code(",$1,");
				gen_sym_name(increment_list[i]);
		  }
		  increment_list[i] = 0;
		}
		
		if(condif_active == 0)
		{
			gen_mov($4, idx);
		}
		//gen_mov($4, idx);
      }
  ;
  

num_exp
  : exp { $$ = $1; }
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
		int t1 = get_type($1);   
		
		code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
		gen_sym_name($1);
		code(",");
		gen_sym_name($3);
		code(",");
		
		//OVO MOZDA TREBA IZBRISATI
		//free_if_reg($3);
		//free_if_reg($1);
		
		$$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
		
	  }
  ;

exp
  : literal
	  {
		  $$ = $1;
	  }
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | _ID _INCREMENT
	  {	  
		$$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
	  
	  
		for(int i=0;i< 10;i++){ 
		  if(increment_list[i] == 0){
			  increment_list[i] = $$;
			  break;
		  }
		}
		
	  }
  | function_call
	 {
		 $$  = $1;
	 }
  | conditional_exp
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
		
		code("\n\t\t\tPUSH\t");
		gen_sym_name($4);
		
		code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", fun_call_params * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
		
		for(int i=0;i< 10;i++){ 
			if(increment_list[i] != 0){
				
				code("\n\t\t\tADDS\t");
				gen_sym_name(increment_list[i]);
				code(",$1,");
				gen_sym_name(increment_list[i]);
		  }
		  increment_list[i] = 0;
		}
      }
  ;

arguments
  : argument
    {
	  $$ = $1;
    }
  | arguments _AROP argument
    {
	  fun_call_params_check_type--;
	  fun_call_params--;
	  $$ = $3;
	  
	  /*code("\n\t\tADDS\t");
	  gen_sym_name($1);
	  code(",");
	  gen_sym_name($3);*/
	  
	  
	  if(get_type(argument_type_check) != get_type($3))
          err("Types not matching!");
		int t1 = get_type($1);   
		
	  code("\n\t\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
	  gen_sym_name($1);
	  code(",");
	  gen_sym_name($3);
	  code(",");
	  //free_if_reg($3);
	  //free_if_reg($1);
	  $$ = take_reg(); //$$ = take_reg();
      gen_sym_name($$);
      set_type($$, t1);
	  
    }
  | arguments _COMMA argument
    {  
	  if(get_type(argument_type_check) != get_type($3))
          err("Types not matching!");
	  
	  code("\n\t\t\tPUSH\t");
	  gen_sym_name($1);
	  $$ = $3;
	}
  ;
  
argument
  : /* empty */ {$$ = 0;}
  | _ID
	{ 
		$$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
		
		int id_idx = lookup_symbol($1, VAR|PAR|GVAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
		
		//free_if_reg(id_idx);
		
		//$$ = 1;
		argument_type_check = $$;
	}
	
  | literal
	{
		if(get_type(fun_call_params_check_type) != get_type($1))
			err("Type of parameter '%d' not valid", fun_call_params);
		fun_call_params_check_type++;
		fun_call_params++;
		
		$$ = $1;
		argument_type_check = $$;
	}
  | _ID _INCREMENT
	  {
		$$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
	  
		int id_idx = lookup_symbol($1, VAR|PAR|GVAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
	
		
		for(int i=0;i< 10;i++){ 
		  if(increment_list[i] == 0){
			  increment_list[i] = $$;
			  break;
		  }
		}
		argument_type_check = $$;
	  }
	  //$$ = 1;
  ;

if_statement
  : if_part %prec ONLY_IF
	{ code("\n@exit%d:", $1); }
  | if_part _ELSE statement
	{ code("\n@exit%d:", $1); }
  ;


if_part
  : _IF _LPAREN
	  {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
	rel_expresions
	  {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3); 
        code("\n@true%d:", $<i>3);
      }	
	  _RPAREN statement
	  {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;
 
check_statement
  : _CHECK _LPAREN check_expression _RPAREN
	_LBRACKET cases
	{
		lab_num++;
		code("\n@L%d:", lab_num);
	}	
	otherwise _RBRACKET
	{
		code("\n@CHECK_CMP%d:", check_cmp_num);
		

		
		for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] != -99){
			  
			  gen_cmp(check_idx, check_cmp[i]);
			  code("\n\t\tJEQ\t@L%d", lab_num_backup);
			  lab_num_backup++;
		  }
		}
		code("\n\t\tJMP\t@L%d", lab_num_backup);
		
		code("\n@CHECK_EXIT%d:", check_exit_num);
		check_idx = -1;
	}
  
  
  
  | _CHECK _LPAREN check_expression _RPAREN
	_LBRACKET cases _RBRACKET
	{
		code("\n@CHECK_CMP%d:", check_cmp_num);
		
		for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] != -99){
			  gen_cmp(check_idx, check_cmp[i]);
			  code("\n\t\tJEQ\t@L%d", lab_num_backup);
			  lab_num_backup++;
		  }
		}
			
		
		
		
		
		code("\n@CHECK_EXIT%d:", check_exit_num);
		check_idx = -1;
	}
  ;
  
check_expression
  : _ID
	  {
		  int id_indx = lookup_symbol($1, VAR|PAR|GVAR);
		  if(id_indx == NO_INDEX)
			   err("'%s' must be defined", $1);
		   
		  check_tip = get_type(id_indx);
		  check_idx = id_indx;
		  
		  //dal treba?
		  lab_num_backup = lab_num + 1;
		  
		  ++check_exit_num;
		  ++check_cmp_num;
		  
		  code("\n\t\tJMP\t@CHECK_CMP%d", check_cmp_num);
		  
		  	  //gen_cmp(check_idx, $2);
			//code("\n\t\tJEQ\t@L%d", lab_num);
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
	  ++lab_num;
	  
	  for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] == -99){
			  check_cmp[i] = $2;
			  break;
		  }
		}
		
		
	  code("\n@L%d:", lab_num);
  }
  _ARROW case_body
  ;

  
case_body
  : statement {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
  | statement {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
	_BREAK _SEMICOLON
  ;
  
otherwise
  : _OTHERWISE _ARROW statement{code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
  | _OTHERWISE _ARROW statement _BREAK _SEMICOLON {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
  ;
  
  
for_statement
  :
  _FOR _LPAREN _TYPE _ID _ASSIGN literal _DOTDOT literal _RPAREN
  {
	  int idx = lookup_symbol($4, VAR|PAR|GVAR);
	  if(idx == NO_INDEX)
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
	  for_active = 1;
	  ++for_exit_num;
	  
	  
	  lit1 = take_reg();
	  lit2 = take_reg();
	  
	  code("\n\t\tMOV \t");
	  gen_sym_name($6);
	  code(",");
	  gen_sym_name(lit1);
	  
	  
	  code("\n\t\tMOV \t");
	  gen_sym_name($8);
	  code(",");
	  gen_sym_name(lit2);

	  
	  while_active = 1;
	  ++lab_num;

	  code("\n@L%d:", lab_num);
	  
	  
	  
	  code("\n\t\tCMPU \t");
	
	  gen_sym_name(lit1);
	  code(",");
	  gen_sym_name(lit2);
  
  
	  code("\n\t\tJEQ \t@L_exit%d", for_exit_num);
	  

	  
	  code("\n@L%d:", ++lab_num);
	  
	  code("\n\t\tADDS\t");
	  gen_sym_name(lit1);
	  code(",$1,");
	  gen_sym_name(lit1);
	  
  }  
  statement
  {
	  
	  /*print_symtab();
	  printf("%d", for_indx);*/
	  
	  clear_symbols(for_indx);
	  for_indx = -1;
	  
	  code("\n\t\tJMP \t@L%d", lab_num-1);
	  code("\n@L_exit%d:", for_exit_num);
	  while_active = 0;
	  for_active = -1;
	  //clear_symbols(for_indx);
	  /*print_symtab();*/
  }
  ;
  
while_statement
  : _WHILE _LPAREN
	  {
		while_active = 1;
		++while_exit_num;
		
		lab_num = lab_num + 2;
		
		while_cmp = lab_num - 1;
		while_stat = lab_num;
		
		code("\n\t\tJMP\t@L%d", while_cmp);

		code("\n@L%d:", while_cmp);

      }	
	rel_expresions
	{
		code("\n@L%d:", while_stat);
	}
	_RPAREN statement
	{
        code("\n\t\tJMP \t@L%d", while_cmp);
		code("\n@L_exit:");
		while_active = 0;
    }
  ;
	
conditional_exp
	: _LPAREN rel_expresions 
		{
			condif_active = 1;
			$<i>$ = ++lab_num;
			code("\n@if%d:", lab_num);
			
		  code("\n\t\t%s\t@false%d", opp_jumps[$2], lab_num); 
		  
		  code("\n@true%d:", lab_num);
		}	
		_RPAREN _QUESTION exp
		{
	
		  gen_mov($6, condif_mov_idx);
		  code("\n\t\tJMP \t@exit%d", lab_num);
		  code("\n@false%d:", lab_num);
		}
		_DOTDOT exp
		{
			if(get_type($9) != get_type($6))
				err("Incompatable types conditional_exp!");
	  
			gen_mov($9, condif_mov_idx);
			
			 
			$$ = $6;
			code("\n@exit%d:", lab_num);
		}
	;	

  
rel_expresions
  : rel_exp
  {
	  $$ = $1;
  }
  | rel_expresions _OR rel_exp
  {
	  $$ = $3;
  }
  | rel_expresions _AND rel_exp
  {
	  $$ = $3;
  }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
		$$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
		
		if(while_active == 1){
			code("\n\t\t%s\t@L_exit%d", opp_jumps[$$], while_exit_num); 
		}
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
		return_exists = 1;
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
		gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));  
      }
	| _RETURN _SEMICOLON
	  {
		return_exists = 1;
		if(get_type(fun_idx) == INT || get_type(fun_idx) == UINT)
          warning("Function should return the specified type!");
		code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
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
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count){
	remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

