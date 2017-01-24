#include <stdio.h>

another_api()
{
	int i;
	int *p;

	i = 5;
	p = &i;
	printf("[JK-11] i= %d, p= %x, *P= %x \n", i, p, *p);
	*p = 6;
	printf("[JK-12] i= %d, p= %x, *P= %x \n", i, p, *p);
	return 0;
}

print_array()
{
	int a[5] = {1,2,3,4,5};
	int *p;
	p=a;

	printf("[JK-21] p= 0x%x, p+1= 0x%x, p+2= 0x%x \n", p, p+1, p+2);
	printf("[JK-22] *p= %d, *(p+1)= %d, *(p+2)= %d \n", *p, *(p+1), *(p+2));
	printf("[JK-23] a[0]= %d, a[1]= %d, a[2]= %d \n", a[0], a[1], a[2]);
	return 0;
}

check_endian()
{
	int i = 0x00000001;

	if (((char *) &i)[0])
		printf ("[JK-31] check_endian: This machine is <Little Endian> ...\n");
	else
		printf ("[JK-32] check_endian: This machine is <Big Endian> ...\n");
	return 0;
}

swap_endian()
{
	int A = 0x12345678;
	int B = 0;

	printf ("[JK-41] swap_endian: Original Value A= 0x%X \n", A);
	B = ((A >> 24) |
		 ((A >> 8) & (0x00FF00)) |
		 ((A << 8) & (0x00FF0000)) |
		 ((A << 24) & (0xFF000000)) );
	printf ("[JK-42] swap_endian: Swap Value B= 0x%X \n", B);
	return 0;
}

swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

swap_main()
{
	int num1, num2;
	num1 = 100;
	num2 = 200;

	printf("[JK-51] Before swap_main: num1= %d, num2= %d \n", num1, num2);
	swap(&num1, &num2);
	printf("[JK-52] After swap_main: num1= %d, num2= %d \n", num1, num2);
	return 0;
}

reverse_number()
{
	int num, r, reverse=0;

	printf("Enter any number:");
	scanf("%d", &num);
	printf("[JK-61] reverse_number: num= %d\n", num);

	while (num) {
		r = num%10;
		reverse = reverse * 10 + r;
		num = num/10;
		printf("[JK-62] reverse_number: r= %d, reverse= %d, num= %d\n", r, reverse, num);
	}
	printf("[JK-62] reverse_number: reverse= %d\n", reverse);
	return 0;
}

main()
{
	int number = 0;
	int *pointer = NULL;
	int rc = 0;
	number = 10;
	pointer = &number;

	printf("[JK-01] main: Pointer's Address : %p \n", &pointer);
	printf("[JK-02] main: Pointer's Value : %p\n", pointer);
	printf("[JK-03] main: Value pointed to = %d\n", *pointer);
	printf("\n");
	rc = another_api();
	printf("[JK-04] main: rc from another_api= %d\n", rc);

	rc = print_array();
	printf("\n");
	printf("[JK-05] main: rc from print_array= %d\n", rc);

	rc = check_endian();
	printf("\n");
	printf("[JK-06] main: rc check_endian print_array= %d\n", rc);

	rc = swap_endian();
	printf("\n");
	printf("[JK-07] main: rc swap_endian print_array= %d\n", rc);

	rc = swap_main();
	printf("\n");
	printf("[JK-08] main: rc swap_main print_array= %d\n", rc);

	printf("\n");
	rc = reverse_number();
	printf("[JK-09] main: rc swap_main reverse_number= %d\n", rc);
}