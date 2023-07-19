#include <bits/stdc++.h>
using namespace std;

class minStack
{
private:
    stack<int> elements;
    stack<int> minElements;

public:
    minStack()
    {
    }
	void push(int num)
    {
        elements.push(num);
        if (minElements.empty() || num <= minElements.top())
        {
            minElements.push(num);
        }
    }
	
    int pop()
    {
        if (elements.empty())
        {
            return -1; 
        }

        int topElement = elements.top();
        elements.pop();
        if (topElement == minElements.top())
        {
            minElements.pop();
        }

        return topElement;
    }
    int top()
    {
        if (elements.empty())
        {
            return -1; // Stack is empty
        }

        return elements.top();
    }

    int getMin()
    {
        if (minElements.empty())
        {
            return -1; // Stack is empty
        }

        return minElements.top();
    }
};
