//OPIS: case statement
//RETURN: 6


int main(){
    int a = 1;
    int b;
	
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
