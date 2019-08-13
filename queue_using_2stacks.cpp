//here two stacks are used to implement queue. push all elements from s1 to s2, given s1 filled first then s2. One more method is to make enqueue costly. Here we did dequeue costly.
//This is preferred. 
#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s1, s2; 

	// Enqueue an item to the queue 
	void enQueue(int x) 
	{ 
		// Push item into the first stack 
		s1.push(x); 
	} 

	// Dequeue an item from the queue 
	int deQueue() 
	{ 
		// if both stacks are empty 
		if (s1.empty() && s2.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 

		// if s2 is empty, move 
		// elements from s1 
		if (s2.empty()) { 
			while (!s1.empty()) { 
				s2.push(s1.top()); 
				s1.pop(); 
			} 
		} 

		// return the top item from s2 
		int x = s2.top(); 
		s2.pop(); 
		return x; 
	} 
}; 

// Driver code 
int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 


//Another method using one stack only
/* deQueue:
  1) If stack1 is empty then error.
  2) If stack1 has only one element then return it.
  3) Recursively pop everything from the stack1, store the popped item 
    in a variable res,  push the res back to stack1 and return res

 int deQueue() 
    { 
        if (s.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        // pop an item from the stack 
        int x = s.top(); 
        s.pop(); 
  
        // if stack becomes empty, return 
        // the popped item 
        if (s.empty()) 
            return x; 
  
        // recursive call 
        int item = deQueue(); 
  
        // push popped item back to the stack 
        s.push(x); 
  
        // return the result of deQueue() call 
        return item; 
    } 

 */



