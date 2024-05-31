#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_Array[5];

public:
	Queues () {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\Queue overflow\n";
			return;
		}

		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_Array[REAR] = num;
	}

	void remove() {
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from queue is: " << queue_Array[FRONT] << "\n";

		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			if (FRONT == max -1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}
	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_Array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			while (FRONT_position <= max - 1) {
				cout << queue_Array[FRONT_position] << "  ";
				FRONT_position++;
			}
		}
	}
};
