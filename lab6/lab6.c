#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int preArray[10];
static int page_fault[100];
static int number_page_fault_FIFO = 1;
static int number_page_fault_OPT = 1;
static int number_page_fault_LRU = 1;
static int number_page_fault_FIFO_1 = 1;
static int number_page_fault_OPT_1 = 1;
static int number_page_fault_LRU_1 = 1;

int Is_in_preArray(int page, int value)
{
	for (int i = 0; i < page; i++)
	{
		if (value == preArray[i])
			return i;
	}
	return -1;
}

int Farest_Element(int *ref, int pivot, int page)
{
	int min = pivot;
	int vt;
	
	for (int i = 0; i < page; i++)
	{
		for (int j = pivot - 1; j >= 0; j--)
		{
			if (preArray[i] == ref[j])
			{
				if (j < min)
				{
					min = j;
					vt = i;
				}
				break;
			}
		}
	}
	return vt;
}

int Farest_Element_Opposite(int *ref, int pivot, int page, int n)
{
	int max = pivot;
	bool flag[10];
	
	for (int i = 0; i < page; i++)
	{
		flag[i] = false;
	}
	int vt = -1;
	
	for (int i = 0; i < page; i++)
	{
		for (int j = pivot + 1; j < n; j++)
		{
			if (preArray[i] == ref[j])
			{
				if (j > max)
				{
					max = j;
					vt = i;
				}
				flag[i] = true;
				break;
			}
		}
	}
	
	for (int i = 0; i < page; i++)
	{
		if (flag[i] == false)
			return i;
	}
	return vt;
}

// Ham in ket qua giai thuat FIFO voi page
void Print_FIFO(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault: %d\n", number_page_fault_FIFO);
	printf("-------\n");
}

// Ham in ket qua giai thuat FIFO voi page + 1
void Print_FIFO_1(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault after(page + 1): %d\n", number_page_fault_FIFO_1);
	printf("\n");
	if (number_page_fault_FIFO < number_page_fault_FIFO_1)
		printf("Occur Belady Anomaly!\n");
	else
		printf("Not occur Belady Anomaly!\n");
}

// Ham in ket qua giai thuat OPT voi page
void Print_OPT(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault: %d\n", number_page_fault_OPT);
	printf("-------\n");
}

// Ham in ket qua giai thuat OPT voi page + 1
void Print_OPT_1(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault after(page + 1): %d\n", number_page_fault_OPT_1);
	printf("\n");
	if (number_page_fault_OPT < number_page_fault_OPT_1)
		printf("Occur Belady Anomaly!\n");
	else
		printf("Not occur Belady Anomaly!\n");
}

// Ham in ket qua giai thuat LRU voi page
void Print_LRU(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault: %d\n", number_page_fault_LRU);
	printf("-------\n");
}

void Print_LRU_1(int total_page[10][100], int n, int page, int ref[100])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", ref[i]);
	}
	printf("\n");
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (total_page[i][j] != -1)
				printf("%d", total_page[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		if (page_fault[i] == 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
	printf("Number of Page Fault after(page + 1): %d\n", number_page_fault_LRU_1);
	printf("\n");
	if (number_page_fault_LRU < number_page_fault_LRU_1)
		printf("Occur Belady Anomaly!\n");
	else
		printf("Not occur Belady Anomaly!\n");
}


// Hien thi giai thuat FIFO voi page
void FIFO(int ref[], int n, int page)
{
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = -1;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = -1;
		else
		{
			current_page++;
			if (current_page == page)
				current_page = 0;
				
			total_page[current_page][j] = ref[j];
			page_fault[j] = 1;
			number_page_fault_FIFO++;
		}
	}
	Print_FIFO(total_page, n, page, ref);
  //--------------------------------------------------------
}

// Hien thi giai thuat FIFO voi page + 1
void FIFO_1(int ref[], int n, int page) 
{
	page = page + 1;
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = -1;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = -1;
		else
		{
			current_page++;
			if (current_page == page)
				current_page = 0;
				
			total_page[current_page][j] = ref[j];
			page_fault[j] = 1;
			number_page_fault_FIFO_1++;
		}
	}
	Print_FIFO_1(total_page, n, page, ref);
}

// Hien thi giai thuat OPT voi page
void OPT(int ref[], int n, int page)
{
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = -1;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = 0;
		else
		{
			if (j < page)
			{
				current_page++;
				total_page[current_page][j] = ref[j];
			}
			else
			{
				int pivot = Farest_Element(ref, j, page);
				total_page[pivot][j] = ref[j];		
			}
			page_fault[j] = 1;
			number_page_fault_OPT++;
		}
	}
	Print_OPT(total_page, n, page, ref);
}

// Hien thi giai thuat OPT voi page + 1
void OPT_1(int ref[], int n, int page)
{
	page = page + 1;
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = -1;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = 0;
		else
		{
			if (j < page)
			{
				current_page++;
				total_page[current_page][j] = ref[j];
			}
			else
			{
				int pivot = Farest_Element(ref, j, page);
				total_page[pivot][j] = ref[j];		
			}
			page_fault[j] = 1;
			number_page_fault_OPT_1++;
		}
	}
	Print_OPT_1(total_page, n, page, ref);
}

// Hien thi giai thuat LRU voi page
void LRU(int ref[], int n, int page)
{
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = 0;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = 0;
		else
		{
			if (j < page)
			{
				current_page++;
				total_page[current_page][j] = ref[j];
			}
			else
			{
				int pivot = Farest_Element_Opposite(ref, j, page, n);
				total_page[pivot][j] = ref[j];		
			}
			page_fault[j] = 1;
			number_page_fault_LRU++;
		}
	}
	Print_LRU(total_page, n, page, ref);
}

// Hien thi giai thuat LRU voi page + 1
void LRU_1(int ref[], int n, int page)
{
	page = page + 1;
	bool IsFault;
	int total_page[10][100];
	int current_page = 0;
	
	for (int i = 0; i < page; i++)
	{
		if (i == 0)
			total_page[i][0] = ref[0];
		else
			total_page[i][0] = 0;
	}
	page_fault[0] = 1;
	
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < page; i++)
		{
			total_page[i][j] = total_page[i][j - 1];
			preArray[i] = total_page[i][j - 1];
		}
		
		if (Is_in_preArray(page, ref[j]) != -1)
			page_fault[j] = 0;
		else
		{
			if (j < page)
			{
				current_page++;
				total_page[current_page][j] = ref[j];
			}
			else
			{
				int pivot = Farest_Element_Opposite(ref, j, page, n);
				total_page[pivot][j] = ref[j];		
			}
			page_fault[j] = 1;
			number_page_fault_LRU_1++;
		}
	}
	Print_LRU_1(total_page, n, page, ref);
}

//--------------------------------------------------------------------


void main()
{
	int page, page_after;
	int temp;
	int ref[11] = { 2, 0, 5, 2, 0, 4, 3, 5, 0, 0, 7 };
	int n = 11;
	
	printf("--- Page Replacement Algorithm ---\n");
	printf("1. Default referenced sequence\n");
	printf("2. Manual input sequence\n");
	scanf("%d", &temp);
	switch (temp)
	{
		case 1: 
			break;
		case 2:
			printf("Nhap so luong: ");
			scanf("%d", &n);
			printf("Nhap danh sach trang: ");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &ref[i]);
			}
			break;
	}
	
	printf("--- Page Replacement Algorithm ---\n");
	printf("Input page frames: ");
	scanf("%d", &page);
	
	printf("___________________________________\n");
	printf("--- Page Replacement Algorithm ---\n");
	printf("1. FIFO algorithm\n");
	printf("2. OPT algorithm\n");
	printf("3. LRU algorithm\n");
	printf("4. All algorithms\n");
	printf("___________________________________\n");

	scanf("%d", &temp);
	switch (temp)
	{
		case 1: 
			printf("--- Page Replacement Algorithm ---\n");
			FIFO(ref, n, page);
			FIFO_1(ref, n, page);
			break;
		case 2:
			printf("--- Page Replacement Algorithm ---\n");
			OPT(ref, n, page);
			OPT_1(ref, n, page);
			break;
		case 3:
			printf("--- Page Replacement Algorithm ---\n");
			LRU(ref, n, page);
			LRU_1(ref, n, page);
			break;	
		case 4: 		
			printf("--- Page Replacement Algorithm ---\n");
			printf("---FIFO---\n");
			FIFO(ref, n, page);
			FIFO_1(ref, n, page);
			printf("___________________________________\n");
			printf("---OPT---\n");
			OPT(ref, n, page);
			OPT_1(ref, n, page);
			printf("___________________________________\n");
			printf("---LRU---\n");
			LRU(ref, n, page);
			LRU_1(ref, n, page);
	}	
}

