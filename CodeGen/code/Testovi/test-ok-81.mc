//OPIS: jedna globalna promenljiva
//RETURN: 2


int main(){
    int a = 2;
    int b;
	
    b = a + (a == 2) ? a : b + 3;
	
	return b;
}
