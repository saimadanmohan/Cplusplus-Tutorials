
Below article is based on the C++11

recommended readings:
https://stackoverflow.com/questions/3064559/how-is-vector-implemented-in-c


#Adding or removing an element to a Vector while iterating over it

https://stackoverflow.com/questions/37900109/adding-an-element-to-a-vector-while-iterating-over-it

1)insert an element at the beginning of the vector while iterating

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	bool to_insert = true;
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
		if(to_insert){
            vec.insert(vec.begin(),6);//insertion at the beginning
			to_insert = !to_insert;
		}
		cout<<*it<<endl;
	}
	return 0;
}
```

Expected Behaviour:

State of the iterator gets invalidated , iterator will return garbage values and may crash sometimes
when you are inserting a new element and it exceeds the vector capacity,in C++11 we are going to allocate 
new memory with increased capacity of vector and the elements will be moved to the new memory locations.old
memory locations may or may not hold the data.

Here the point to be noted the growth of the vector is  often follow a non-linear growth pattern,to avoid frequent allocations.

2)insert an element at the end of the vector while iterating

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	bool to_insert = true;
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
		if(to_insert){
			vec.push_back(6);//insertion at the end
			to_insert = !to_insert;
		}
		cout<<*it<<endl;
	}
	return 0;
}
```

Expected Behaviour:
State of the iterator gets invalidated , iterator will return garbage values and may crash sometimes


https://stackoverflow.com/questions/9927163/erase-element-in-vector-while-iterating-the-same-vector

3)deleting elements of the vector while iterating

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	bool to_remove = true;
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
		if(to_remove){
			vec.erase(vec.begin()+2,vec.begin()+4);
			to_remove = !to_remove;
		}
		cout<<*it<<endl;
	}
	return 0;
}
```

Expected Behaviour:
1 2 3 4 5
0 1 2 3 4
when we are erasing the elements at indices 3 and 4 using the below statement
```
(vec.erase(vec.begin()+2,vec.begin()+4);)
```
the elements following the elements will be shifted in the memory.

when all the elements are deleted
```
vec.erase(vec.begin(),vec.end();
```
as the vector doesnot have any elements the programme crashes as we are trying to print value at the current iterator
position.

