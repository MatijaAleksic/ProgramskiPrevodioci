//OPIS: Sanity check za miniC gramatiku

int f(int x) {
    int y;
    return x + 2 - y;
}

unsigned f2() {
    return 2u;
}

unsigned ff(unsigned x) {
    unsigned y;
    return x + f2() - y;
}

//funkcija sa vise promjenjivih
void f3(int a, int b, int c){
	a = 5;
	b = 3;
	return;
}

//return; za void
void f4(){
	return;
}
//vodi funkcija bez returna
void f5(){
}

//int funkcija sa returnom;
int f6(){
	return 1;
}

//int funckija sa ruturn parametar
int f7(int b){
	return b;
}

int main() {
    int a,b = 5,c;
    int aa;
	int k = 2;
    int bb;
    int d;
    unsigned u;
    unsigned w;
    unsigned uu;
    unsigned ww;

    //poziv funkcije
    a = f(3);
	
	//inkrement
	c = b++;
	
	//poziv funkcije sa inkrementom
    a = f(b);
   
    //if iskaz sa else delom
    if (a < b)  //1
        a = 1;
    else
        a = -2;

    if (a + c == b + d - 4) //2
        a = 1;
    else
        a = 2;

    if (u == w) {   //3
        u = ff(1u);
        a = f(11);
    }
    else {
        w = 2u;
    }
    if (a + c == b - d - -4) {  //4
        a = 1;
    }
    else
        a = 2;
    a = f(42);

    if (a + (aa-c) - d < b + (bb-a))    //5
        uu = w-u+uu;
    else
        d = aa+bb-c;

    //if iskaz bez else dela
    if (a < b)  //6
        a = 1;

    if (a + c == b - +4 and b < 3 or a < 5)    //7
        a = 1;

	//ugnjezdeni if
	if(a < b){
		if(b < 5){
		}
		else{
		}
	}else
	{
		b = 4;
	}
	
	//poziv sa vise promjenjivih
	f3(a,b,c);
	
	//blok
	{
		int z = 5;
		a = z + 3;
		b = 7;
	}
	
	//while statement
	while(a > 5){
		b = b++;
	}
	
	//while za and or 
	while(a > 5 and b < 3 or c > 3){
		b = b + 1;
	}
	
	//for iskaz
	for (int i = 3 : -3){
		a = a + i;
		b = b - i;
	}
	
	//for iskaz za -
	for (int i = -5 : 1)
		a = b - i;
		
		
	//case iskaz
	check (a){
	  case 1 =>
		a = a + 5;
		break;
	  case 5 =>
	  {
		b = 3;
	  }
	  case 6 =>
	  {
		return 1;
	  }
	  otherwise =>
		a = a + b;
		break;
  }
  
	return 1;
}

