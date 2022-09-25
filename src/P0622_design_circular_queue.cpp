#include <common_headers.h>

class MyCircularQueue {
	struct QueueNode
	{
		QueueNode* next_ptr{ nullptr };
		QueueNode* previous_ptr{ nullptr };
		int value{ -2 };
		QueueNode() = default;
	};

	QueueNode* start_{ nullptr };
	QueueNode* end_{ nullptr };
	int capacity_{ 0 };
	int length_{ 0 };
public:
	MyCircularQueue(int k) {
		start_ = new QueueNode();
		end_ = start_;
		capacity_ = k--;
		QueueNode* current = start_;
		while (k > 0)
		{
			current->next_ptr = new QueueNode();
			current->next_ptr->previous_ptr = current;
			current = current->next_ptr;
			--k;
		}
		current->next_ptr = start_;
		start_->previous_ptr = current;
	}

	~MyCircularQueue()
	{
		if (capacity_ > 0)
		{
			QueueNode* current = start_;
			while (current->next_ptr != nullptr && capacity_ > 1)
			{
				current = current->next_ptr;
				--capacity_;
				delete current->previous_ptr;
			}
			delete current;
		}
	}

	bool enQueue(int value) {
		if (length_ == capacity_)
		{
			return false;
		}
		if (length_ != 0)
		{
			end_ = end_->next_ptr;
		}
		end_->value = value;
		length_++;
		return true;
	}

	bool deQueue() {
		if (length_ == 0)
		{
			return false;
		}
		length_--;
		if (length_ != 0)
		{
			start_ = start_->next_ptr;
		}
		return true;
	}

	int Front() const
	{
		if (length_ > 0)
		{
			return start_->value;
		}
		return -1;
	}

	int Rear() const
	{
		if (length_ > 0)
		{
			return end_->value;
		}
		return -1;
	}

	bool isEmpty() const
	{
		if (length_ == 0)
		{
			return true;
		}
		return false;
	}

	bool isFull() const
	{
		if (length_ == capacity_)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	{
		MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
		expect(myCircularQueue->enQueue(1)); // return True
		expect(myCircularQueue->enQueue(2)); // return True
		expect(myCircularQueue->enQueue(3)); // return True
		expect(!myCircularQueue->enQueue(4)); // return False
		expect(eq(3, myCircularQueue->Rear()));     // return 3
		expect(myCircularQueue->isFull());   // return True
		expect(myCircularQueue->deQueue());  // return True
		expect(myCircularQueue->enQueue(4)); // return True
		expect(eq(4, myCircularQueue->Rear()));     // return 4
	}

	{
		MyCircularQueue* my_circular_queue = new MyCircularQueue(3);
		expect(my_circular_queue->enQueue(2));
		expect(eq(2, my_circular_queue->Rear()));
		expect(eq(2, my_circular_queue->Front()));
	}
	{
		MyCircularQueue* my_circular_queue = new MyCircularQueue(2);
		expect(my_circular_queue->enQueue(4));
		expect(eq(4, my_circular_queue->Rear()));
		expect(my_circular_queue->enQueue(9));
		expect(my_circular_queue->deQueue());
		expect(eq(9, my_circular_queue->Front()));
	}
	{
		MyCircularQueue* my_circular_queue = new MyCircularQueue(8);
		expect(my_circular_queue->enQueue(0));
		expect(my_circular_queue->enQueue(4));
		expect(my_circular_queue->enQueue(6));
		expect(my_circular_queue->enQueue(3));
		expect(my_circular_queue->deQueue());
		expect(eq(4, my_circular_queue->Front()));
		expect(my_circular_queue->deQueue());
		expect(eq(6, my_circular_queue->Front()));
		expect(my_circular_queue->deQueue());
		expect(eq(3, my_circular_queue->Front()));
	}
	{
		MyCircularQueue* my_circular_queue = new MyCircularQueue(8);
		expect(my_circular_queue->enQueue(0));
		expect(my_circular_queue->deQueue());
		expect(eq(-1, my_circular_queue->Front()));
		expect(eq(-1, my_circular_queue->Rear()));
		expect(my_circular_queue->enQueue(6));
		expect(eq(6, my_circular_queue->Front()));
		expect(eq(6, my_circular_queue->Rear()));
	}

}