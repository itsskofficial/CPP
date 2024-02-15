//include the libraries and use standard namespace
#include <iostream>
using namespace std;

template <typename t> //creating a template object t with class typename

void selection_sort(t arr[], int n) //accepting array of any data type t
{
    int i, j, min_itself=0,flag;
    t temp, lowest; //declaring variables with any data type t
    //selection sort algorithm
    while (min_itself!=n)
    {
        for (i = 0; i < n; i++)
        {   
            flag = 0;
            lowest = arr[i];

            for (j = i + 1; j < n; j++)
            {
                if (arr[i]>arr[j])
                {
                    lowest = arr[j];
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flag++;
                }
            }

            if (flag==0)
            {
                min_itself++;
            }
        }
    }

    //displaying the array after sorting
    cout << "\nSorted array: \n";
    for (i = 0; i < n;i++)
    {
        cout << arr[i]<<"\t";
    }
}

int main()
{
    //creating 3 arrays each of one data type
    int arr1[10];
    float arr2[10];
    char arr3[10];
    char temp;
    int n,i,c;
    cout << "Enter no of array elements: ";
    cin >> n;
    cout << "\n1.Integer\n2.Float\n3.Character\nEnter data type of array: ";
    cin >> c;
    cout<<"\nEnter array elements now:\n";
    switch (c)
    {
        case 1:
        {
            for (i = 0; i < n; i++)
            {
                cin >> arr1[i];
            }
            selection_sort<int>(arr1, n);
            break;
        }

        case 2:
        {
            for (i = 0; i < n; i++)
            {
                cin >> arr2[i];
            }
            selection_sort<float>(arr2, n);
            break;
        }
        
        case 3:
        {
            for (i = 0; i < n; i++)
            {
                cin >> arr3[i];
            }
            selection_sort<char>(arr3, n);
            break;
        }
        default:
        {
            cout << "Wrong choice";
            break;
        } 
    }
    return 0;
}