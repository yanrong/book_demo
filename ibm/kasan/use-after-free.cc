//To complie: g++ -O -g -fsanitize=address use-after-free.cc
int main(int argc, char **agrv)
{
	int *array = new int[10];
	delete []array;
	return array[argc];
}
