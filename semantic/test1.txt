int main() {
	int x;
	int y;
	x = 2;
	y = 3;
	{
		int x;
		x = 5;
		y = x + y;
		
		{
			int x;
			x = 6;
		}
	}
  	return x + y;	
}

int main1() {
  int x;
  x = 2;
  {
	int z;
	x = 5;
  }
  return x;
}

