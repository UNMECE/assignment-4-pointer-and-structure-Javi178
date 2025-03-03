#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
	int size = 5;
	Item *item_list = (Item *)malloc(size * sizeof(Item));


        if (argc < 2)
        {
                printf("error invalid argument count: %s\n", argv[0]);
                return 0;
        }

	int user_input = atoi(argv[1]);

        if (user_input <= 0)

        {
                printf("error input can not be a negative number: %d\n",size);
                return 0;
        }


	add_item(item_list, 10.00, "1023","Breakfast", "pancakes", 0);
	add_item(item_list, 5.00, "9099", "Snacks", "Cookies", 1);
	add_item(item_list, 15.00, "14512","Lunch", "Turkey sandwich", 2);
	add_item(item_list, 4.00, "01", "dariy", "milk",3);
	add_item(item_list, 5.00, "02", "dariy", "eggs", 4);
	
	print_items(item_list, size);
	
	int i = 0;
	while (i < size && strcmp(item_list[i].sku, argv[1]) != 0)
	{
		i++;	
	 
	}
	if(i < size)
	{
	printf("\n");
	printf("sku found!:: %s\n", item_list[i].sku);
	printf("item name: %s\n", item_list[i].name);
	}



	free_items(item_list, size);

}	




void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	item_list[index].price = price;
	item_list[index].sku = (char *)malloc(strlen(sku) + 1);
	item_list[index].category = (char *)malloc(strlen(category) + 1);
	item_list[index].name = (char *)malloc(strlen(name) + 1);
	
	strcpy(item_list[index].sku, sku);
	strcpy(item_list[index].category, category);
	strcpy(item_list[index].name, name);
			
}



void free_items(Item *item_list, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		free(item_list[i].sku);
                free(item_list[i].category);
                free(item_list[i].name);

	}

	free(item_list);
}

double average_price(Item *item_list, int size)
{	
	double full_price = 0;
	int i;
	for(i = 0; i <size ; i++)
	{
		full_price += item_list[i].price;	
	}
	return full_price/size;
}

void print_items(Item *item_list, int size)
{
	int i;
	for(i =0 ; i < size; i ++)
	{
		
		printf("################ \n");
		printf("Name: %s\n", item_list[i].name);  	
		printf("category: %s\n", item_list[i].category);
        	printf("sku: %s\n", item_list[i].sku);        
		printf("price: %f\n", item_list[i].price);
		printf("\n");        
	}
}
	
