//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

#include "CB_Task_1_Sandbox.h"



/*
*
* Function Name: get_sensor_values
* Input: pointer to integer variables of the sensors(by call by reference)
* Output: void
* Logic: takes values from the ADC_conversion function,converts it into integer type
* Example Call: get_sensor_values(&l, &m, &r);//takes values for left, middle and right sensor
 */
void get_sensor_values(int* x, int* y, int* z)
{
	*x = int(ADC_Conversion(1));
	*y = int(ADC_Conversion(2));
	*z = int(ADC_Conversion(3));
}

/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/

void forward_wls(unsigned char node)
{
	int l, m, r;
	node = int(node);
	//printf("value of node is: %d", node);
	int i = 1;
	for (int i = 1; i <= node;)
	{
		_delay_ms(50);
		get_sensor_values(&l, &m, &r);

		if (l == 0 && r == 0 && m == 255)
		{
			forward();
			_delay_ms(50);
			velocity(150, 150);
		}

		if (l == 255 && r == 255 && m == 255 || l == 0 && r == 255 && m == 255 || l == 255 && r == 0 && m == 255)
		{
			forward();
			_delay_ms(200);

			//printf("node reached \n");
			i++;




		}
		if (l == 0 && r == 255 && m == 0)
		{
			velocity(250, 100);

		}
		if (l == 255 && r == 0 && m == 0)
		{
			velocity(100, 250);
		}
		//	printf("value of i: %d \n", i);
	}

}

/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	int l, m, r;
	//printf("function called \n");
	do
	{
		//printf("Turning left \n");

		get_sensor_values(&l, &m, &r);
		left();
	} while (l == 0 && m != 225 && r == 0);
	left();
	_delay_ms(25);
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	int l, m, r;
	//printf("function called \n");
	do
	{
		//printf("Turning right \n");

		get_sensor_values(&l, &m, &r);
		right();
	} while (l == 0 && m != 225 && r == 0);
	right();
	_delay_ms(25);
}

void forward_wlsc(unsigned char node)
{
	int l, m, r;
	node = int(node);
	printf("value of node is: %d", node);
	int i = 1;
	for (int i = 1; i <= node;)
	{
		_delay_ms(50);
		get_sensor_values(&l, &m, &r);

		if (l == 0 && r == 0 && m == 255 || l == 225 && r == 255 && m == 0)
		{
			forward();
			_delay_ms(1);
			velocity(50, 50);
			_delay_ms(50);
		}

		if (l == 0 && r == 0 && m == 0)
		{
			forward();
			_delay_ms(400);

			printf("node reached \n");
			i++;




		}
		if (l == 0 && r == 255 && m == 0 || l == 225 && r == 0 && m == 255)
		{
			velocity(100, 0);
		}
		if (l == 255 && r == 0 && m == 0 || l == 0 && r == 255 && m == 225)
		{

			velocity(0, 100);
		}
		printf("value of i: %d \n", i);
	}

}

void forward_wlsg(unsigned char node)
{
	int l, m, r;
	node = int(node);
	//printf("value of node is: %d", node);
	int i = 1;
	for (int i = 1; i <= node;)
	{
		_delay_ms(50);
		get_sensor_values(&l, &m, &r);

		if (l == 0 && r == 0 && m == 255)
		{
			forward();
			//_delay_ms(50);
			velocity(100, 100);
			_delay_ms(5);
		}

		if (l == 255 && r == 255 && m == 255 || l == 0 && r == 225 && m == 225 || l == 255 && r == 0 && m == 225)
		{
			forward();
			_delay_ms(230);

			//printf("node reached \n");
			i++;




		}
		if (l == 0 && r == 255 && m == 0)
		{
			velocity(150, 110);

		}
		if (l == 255 && r == 0 && m == 0)
		{
			velocity(110, 150);

		}
		//	printf("value of i: %d \n", i);
	}
	/*int l, m, r;
	node = int(node);
	//printf("value of node is: %d", node);
	int i = 1; int e = 3;
	for (int i = 1; i <= node;)
	{
		_delay_ms(50);
		get_sensor_values(&l, &m, &r);

		if (l == 0 && r == 0 && m == 255)
		{
			forward();
			e = 3;

		}

		if (l == 255 && r == 255 && m == 255 || l == 0 && r == 255 && m == 255 || l == 255 && r == 0 && m == 255)
		{
			forward();
			_delay_ms(250);

			//printf("node reached \n");
			i++;




		}
		if (l == 0 && r == 255 && m == 0)
		{
			velocity(250, 200);
			e = 1;
		}
		if (l == 255 && r == 0 && m == 0)
		{

			velocity(200, 250);
			e = 2;
		}
		if (l == 0 && r == 0 && m == 0)
		{

			if(e==2)
			{
				velocity(50, 150);
			}
			if (e == 3)
			{
				velocity(150, 50);
			}

		}
	   /* if (l == 0 && r == 0 && m == 0)
		{
			printf("loop 0 \n");
			int p = 0, q = 0;
			while (p<500)
				{
				printf("\n in loop p");
					//printf("Turning right \n");

					get_sensor_values(&l, &m, &r);
					right();

					if(l == 0 && m == 225 && r == 0)
					{
						printf("\n breaked");
						break;
					}
					p++;
					printf("\n value of p is: %d", p);

				}
			while ( q < 1000)
			{
				//printf("Turning left \n");
				printf("\n in loop p");
				get_sensor_values(&l, &m, &r);
				left();


				if (l == 0 && m == 225 && r == 0)
				{
					printf("\n breaked");
					break;
				}
				q++;
				printf("\n value of q is: %d", q);

			}

		}


	}*/
}
void forward_wlsr(unsigned char node)
{
	int l, m, r;
	node = int(node);
	//printf("value of node is: %d", node);
	int i = 1;
	for (int i = 1; i <= node;)
	{
		_delay_ms(50);
		get_sensor_values(&l, &m, &r);

		if (l == 0 && r == 0 && m == 255)
		{
			forward();
			_delay_ms(1);
			velocity(30, 90);
			_delay_ms(10);

		}

		if (l == 255 && r == 255 && m == 255 || l == 0 && r == 255 && m == 255 || l == 255 && r == 0 && m == 255)
		{
			forward();
			_delay_ms(250);

			//printf("node reached \n");
			i++;




		}
		if (l == 0 && r == 255 && m == 0)
		{
			velocity(100, 0);
		}
		if (l == 255 && r == 0 && m == 0)
		{

			velocity(0, 100);
		}

		//printf("value of i: %d \n", i);
	}

}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
/*void e_shape(void)
{
	forward_wls(1);
	left_turn_wls();
	_delay_ms(1000);
	forward_wls(2);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	stop();
}
*/

/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{

	forward_wls(1);
	//stop();
	//_delay_ms(1000);
	right_turn_wls();
	//stop();
	//_delay_ms(1000);
	forward_wls(4);
	//stop();
	//_delay_ms(1000);
	left_turn_wls();
	//_delay_ms(1000);
	forward_wlsr(1);
	left_turn_wls();
	forward_wlsr(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wlsg(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward();
	_delay_ms(1000);
	forward_wlsc(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	stop();

}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	//write your task 1.2 logic here
}