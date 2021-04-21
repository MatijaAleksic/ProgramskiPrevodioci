int main()
{
	int a,b;
	a = 5;
	b = 4;
	
	check(a){
		case 1 =>
			a = a+ 5;
			break;
		case 2 =>
		{
			b = 3;
		}
		otherwise =>
			a = a + b;
			break;
	}
	return 1;
}