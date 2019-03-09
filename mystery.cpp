#include <iostream>
#include <vector>
using namespace std;


void print(auto A)
{
   for (auto a : A) 
        cout <<a<<" ";

   cout<<endl;
}

void mystery1(auto& Data)
{
  cout<<endl<<"Mystery 1"<<endl<<"---------------------"<<endl;

  for (unsigned int i = 0 ; i < Data.size( ) ; i++)
  {
    for ( int j = 0 ; j < i ; j++)
	if ( Data[ i ] < Data[ j ] )
	    swap( Data[ i ] , Data[ j ] );

    print(Data);
  }//end outer for (this brace is needed to include the print statement)

}

void mystery2(auto& Data)
{
	cout<<endl<<"Mystery 2"<<endl<<"---------------------"<<endl;

	int minIndex, temp; 

	for (unsigned int i = 0; i < Data.size() -1; i ++) 
	{
		minIndex = i;
		
		//to find smallest value in unsorted data
		for (unsigned int j = i + 1; j < Data.size(); j++) 
		{
			if (Data [j] <  Data[minIndex]) 
			{
				minIndex = j;
			}//endif
		}//end inner for 
		if (minIndex != i)
		{
			temp = Data [i];
			Data[i] = Data[minIndex];
			Data[minIndex] = temp;
		
		}//endif
	print(Data);
	}//end for


}//end mystery 2

void mystery3(auto& Data)
{
	cout<<endl<<"Mystery 3"<<endl<<"---------------------"<<endl;
	
	int  moveItem, insertVal;
	
	for (unsigned int nextIndex = 1; nextIndex < Data.size(); nextIndex++)
	{
		insertVal = Data[nextIndex];
		moveItem = nextIndex;
		
		while (moveItem > 0 && Data[moveItem - 1] > insertVal) 
		{
			Data[moveItem] = Data[moveItem-1];
			moveItem --;			
		}//endwhile
		Data [moveItem] = insertVal;
		print(Data);

	} //endfor
	
}//endmystery 3

int main()
{
    
  vector<int> Data = {36, 18, 22, 30, 29, 25, 12};

  vector<int> D1 = Data;
  vector<int> D2 = Data;
  vector<int> D3 = Data;

  mystery1(D1);
  mystery2(D2);
  mystery3(D3);

}
