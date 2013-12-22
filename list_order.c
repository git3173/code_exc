typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char UCHAR;

typedef struct NODE 
{
	NODE* pNext;
	DWORD val; 
};

typedef struct RECORD
{
	WORD valid;
	WORD index;
	DWORD val;
	DWORD count;
	NODE *pNode;
};

#define MAX_ITEM 1000
#define OBJECT_IDX 200

RECORD data[MAX_ITEM];

void init_data()
{
	WORD i;

	for (i = 0; i < MAX_ITEM; i++)
	{
		data[i].valid = 0;
		data[i].index = i;
		data[i].val = 0;
		data[i].count = 0;
		data[i].pNode = NULL;
	}
}

void store_value(DWORD val)
{
	WORD index;

	// get the index;
	index = val & 999;

	// allocate a list node to store the value
	NODE* pNode;
	pNode = (NODE *)malloc(sizeof(NODE));

	if (pNode == NULL)
	{
		log_msg("error");
		return;
	}

	pNode->pNext = NULL;
	pNode->val = val;

	// insert the node at head
	pNode->pNext = data[index].pNode;
	data[index].pNode = pNode;

	// make it valid
	if (data[index].count == 0)
	{
		data[index].valid = 1;
	}

	// count the value number
	data[index].count++;

	return;
}

void get_specific_data()
{
	WORD i;
	WORD j;
	NODE* pNode = NULL;

	for (i = 0; i++; i < MAX_ITEM)
	{
		if (data[i].valid == 0)
		{
			continue;
		}

		if (data[i].count < OBJECT_IDX)
		{
			data[i].val = data[i].pNode->val; // todo
		}
		else
		{
			j = 1;
			pNode = data[i].pNode;

			// get the No. 200's value
			while (j < OBJECT_IDX)
			{
				pNode = pNode->pNext;

				j++;
			} 

			data[i].val = pNode->val;
		} 
	}
}

void swap_record(RECORD* val1, RECORD* val2)
{
	RECORD temp;

	memcpy(&temp, val1, sizeof(RECORD));
	memcpy(val1, val2, sizeof(RECORD));
	memcpy(val2, val1, sizeof(RECORD));		
}

UCHAR compare_record(DWORD val1, DWORD val2)
{
	if (val1 > val2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 


void order_data() 
{
	WORD i;
	WORD j;

	for (i = 0; i < MAX_ITEM - 1; i++)
	{
		if data[i].valid == 0)
		{
			continue;
		}

 		for (j = i + 1; j < MAX_ITEM; j++)
 		{
			if data[j].valid == 0)
			{
				continue;
			}			
			
			if (compare_record(data[i].val, data[j].val))
			{
				swap(&data[i], &data[j]);
			}
		}
	}	
}

void release_data()
{
	WORD i;
	NODE* pNode1, pNode2;

	for (i = 0; i < MAX_ITEM; i++)
	{
		if data[i].valid == 0)
		{
			continue;
		}

		pNode1 = data[i].pNode;

		while (pNode1 != NULL)
		{
			pNode2 = pNode1;
			
			pNode1 = pNode1->pNext; 

			free(pNode2); 
		} 
	}

	return;
}
