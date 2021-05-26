//OPIS: case statement
//RETURN: 7


int main(){
    int a = 6;
    int b = 1;
	
	check (a){
		case 1 =>
			a = a + 5;
			break;
		case 5 =>
		{
			b = 3;
		}
		otherwise =>
			a = a + b;
	}
	
	return a;
}
