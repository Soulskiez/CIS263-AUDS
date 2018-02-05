
/*****************************************************************
 * Almost Useless Data Structure. Program that will hold any type
 * of object. 
 *
 * @author Tyler Solnikowski
 * @version 1
 * *****************************************************************/

/** include that contains the random class needed */
#include <cstdlib>


template <typename T>

class AUDS  {


	public:
		/*****************************************************************
 		Constructor that creates the array we need 
 		*****************************************************************/

		AUDS(){
			 myData = new T[initialSize];
		};

		/*****************************************************************
		Copy constructor that performs a deep copy of our AUDS object
		@param other the list that we will be passing in.
		*****************************************************************/

		AUDS(const AUDS &other){
			initialSize = other.initialSize;
                        currentSize = other.currentSize;
                        myData = new T[initialSize];
                        for(int i = 0; i < currentSize; i++){
                       		 myData[i] = other.myData[i];
			}

		};

		/*****************************************************************
 		Copy operator that performs a copy-and-swap to set one object 
		equal to another.
		@param other A list that we want to compare.
		@return *this The objects that we have swapped.
		*****************************************************************/

		AUDS& operator=(AUDS other){
			std::swap(initialSize = other.initialSize);
			std::swap(currentSize = other.currentSize);
			std::swap(myData = other.myData);
			
			return *this;
		};

		/*****************************************************************
 		Destructor that gives back memory that we borrowed.
		*****************************************************************/

		~AUDS(){
			delete[] myData;
		};

		/*****************************************************************
 		Method that returns the current number of objects we are holding.
		@return currentSize The current size of our list.
		*****************************************************************/

		int size(){
			return currentSize;	
		};

		/*****************************************************************
 		Adds the generic element to the data structure
		@param x The list object we previously created that we want to add.
		*****************************************************************/

		void push(T x){
		
			if(currentSize == initialSize){
				int largerSize = initialSize * 1.5;
                       		 T* temp = new T[largerSize];

                       		 for(int i = 0; i < currentSize; i++){
                                	temp[i] = myData[i];
                       		 }
				delete[] myData;
                       		 myData = temp;
				initialSize = largerSize;
				}
			myData[currentSize] = x;
			currentSize++;
		};

		/*****************************************************************
 		Removes a random item from the list. Moves the last item in the 
		array to the spot of the element that we just removed.
		@return randoList The new list that has a random element removed
			and the last element removed to that point.
		*****************************************************************/

		T pop(){
			int randoSpot = rand() % currentSize;
			T randoList = myData[randoSpot];
			myData[randoSpot] = myData[currentSize--];

			return randoList;
		};

	private:

		/**Initial size of the list being 100  */

		int initialSize = 100;

		/**The size of the list at certain points of runtime and parameters */

		int currentSize = 0;

		/**Variable to hold the list object. */

		T* myData;


};
