//OPIS: u case naredbi nisu isti tipovi


void main()
{
	int a;
	
	
	check (a){
	  case 1 =>
		a = a + 5;
		break;
	  case 5u =>
		{
			b = 3;
		}
	  otherwise =>
		a = a + b;
	  }
}