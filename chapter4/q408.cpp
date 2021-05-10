#include<iostream>

template<class T>
class Stack
{
    private:
        struct Node
	    {
	    	T data;
	    	Node *next;
	    };
	    Node *head;
	    Node *p;
	    int length;
    
    public:
		class Iterator;
		class ConstIterator;
		const Iterator begin()
		{
			return Iterator(p);
		}
        const Iterator end()
		{
			return NULL;
		}
        Stack()
	    {
		    head = NULL;
		    length = 0;
	    }

		Stack(const Stack &copy_obj) : length(copy_obj.length)
		{
			if (copy_obj.head == NULL) {
				head = NULL;
			} else {
				Node *tmp = new Node;
				tmp = copy_obj.p;
				p = new Node;
				head = p;
				p->data = tmp->data;
				for (int i = 0; i < length - 1; i++) {
					head->next = new Node;
					head = head->next;
					tmp = tmp->next;
					head->data = tmp->data;
				}
				head->next = NULL;
			}
		}

		Stack(Stack &&move_obj)
			: head(std::move(move_obj.head)), p(std::move(move_obj.p)),
			length(move_obj.length) {}

	    void push(T n)
	    {
		    Node *q = new Node;
	    	q->data = n;
	    	if (head == NULL) {
	    		q->next = head;
	    		head = q;
	    		p = q;
	    	}
	    	else {
	    		q->next = p;
	    		p = q;
	    	}
	    	length++;
	    }
    
	    T pop()
	    {
	    	if (length <= 0) {
	    		abort();
	    	}
	    	Node *q;
	    	T data;
	    	q = p;
	    	data = p->data;
	    	p = p->next;
	    	delete(q);
	    	length--;
	    	return data;
	    }

	    int size()
	    {
	    	return length;
	    }

	    T top()
	    {
	    	return p->data;
	    }
};

// int main(int argc, char const *argv[])
// {
//     Stack<int> test_stack;
//     test_stack.push(5);
// 	test_stack.push(4);
// 	Stack<int> test_copy_stack(test_stack);
// 	std::cout << test_stack.size() << test_stack.top()
// 		<< test_stack.pop() << test_stack.pop() << '\n';
// 	Stack<int> test_move_stack(test_copy_stack);
// 	std::cout << test_move_stack.size() << test_move_stack.top()
// 		<< test_move_stack.pop() << test_move_stack.pop() << '\n';	
//     return 0;
// }
