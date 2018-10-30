#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

/* GLOBAL VARIABLES */

vector<vector<float>> input = {
	{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0 },
	{ 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1 }
};

vector<vector<float>> desiredoutput = {
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
};
/* The vector noise_immunity_results stores the max # of bit flips required to trick the network for each letter. */
vector<float> noise_immunity_results = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f }; 

float input_to_hidden1_weights[35][35]; // Matrix for weights from input layer to hidden layer

float hidden2_to_output_weights[35][26]; // Matrix for weights from hidden layer to output layer

int maxindex; // Storing the index of max neuron output

float maxloss;

/* HELPER FUNCTIONS */
float logistic_sigmoid_activation(float x) {
	float neg_x = x * -1;
	return 1 / (1 + exp(neg_x));
}

float tanh_activation(float x) {
	return tanh(x);
}

float sigmoid_prime(float x) {
	return x*(1.0f - x);
}

float tanh_prime(float x) {
	return (1.0f - (x * x));
}
// ReLU extra credit
float relu_activation(float x) {
	if (x >= 0)
		return x;
	else return 0.0f;
}

float relu_prime(float x) {
	if (x > 0)
		return 1.0f;
	else return 0.0f;
}

void init() {
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			int randnum = rand() % 21 + (-10);
			float temp = randnum / 100.0;
			input_to_hidden1_weights[i][j] = temp;
		}
	}
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 26; j++) {
			int randnum = rand() % 21 + (-10);
			float temp = randnum / 100.0;
			hidden2_to_output_weights[i][j] = temp;
		}
	}
}

void forward_feed(vector<float> in, vector<float> out, float alpha, bool print, bool printmax, bool printloss, int index) {
	float sum = 0;
	float temparray[35];
	float temparray_26[26];
	float inputarray[35];
	float outputarray[26];
	float deltas[35]; // errors!
	float deltas_26[26]; // more errors


	for (int i = 0; i < 35; i++) {
		inputarray[i] = in.at(i);
	}

	for (int j = 0; j < 35; j++) { // Dot product for input to hidden
		sum = 0;
		for (int i = 0; i< 35; i++) {
			sum += (input_to_hidden1_weights[i][j] * inputarray[i]);
		}
		temparray[j] = sum;
	}

	for (int i = 0; i < 35; i++) { // Tanh sigmoid activation
		temparray[i] = tanh_activation(temparray[i]);
		//temparray[i] = relu_activation(temparray[i]);
	}

	for (int i = 0; i < 35; i++) { // make input array for next layer
		inputarray[i] = temparray[i];
	}

	for (int j = 0; j < 26; j++) { // Dot product for hidden to output
		sum = 0;
		for (int i = 0; i < 35; i++) {
			sum += (hidden2_to_output_weights[i][j] * inputarray[i]);
		}
		temparray_26[j] = sum;
	}

	for (int i = 0; i < 26; i++) { // Logistic sigmoid activation
		temparray_26[i] = logistic_sigmoid_activation(temparray_26[i]);
	}


	for (int i = 0; i < 26; i++) { // make input array for next epoch
		outputarray[i] = temparray_26[i];
	}

	if (print == true) { // If we want to print out the output
		cout << (char)(index + 65) << ": " << outputarray[index];
		cout << "\n\n";
	}

	if (printmax == true) { // If we are performing a noise test
		float max = 0.0f;
		maxindex = 0;
		for (int i = 0; i < 26; i++) {
			if (outputarray[i] > max) {
				max = outputarray[i];
				maxindex = i;
			}
		}
	}

	/*Determining loss*/
	float loss = 0.0f;
	for (int i = 0; i < 26; i++) {
		loss += (1.0f / 2.0f) * (pow(outputarray[i] - out.at(i), 2));
	}

	if (printloss) {
		if (maxloss == 0.0f)
			cout << "Maximum Loss: " << loss << endl;
		else cout << "Accuracy: " << maxloss - loss;
	}
}

void back_propagation(vector<float> in, vector<float> out, float alpha, bool print, bool printmax, bool printloss, int index) {
	float sum = 0;
	float temparray[35];
	float temparray_26[26];
	float inputarray[35];
	float outputarray[26];
	float deltas[35]; // errors!
	float deltas_26[26]; // more errors


	for (int i = 0; i < 35; i++) {
		inputarray[i] = in.at(i);
	}

	/* Learning time! */
	/******************************** FORWARD FEED PHASE **************************************/
	for (int j = 0; j < 35; j++) { // Dot product for input to hidden
		sum = 0;
		for (int i = 0; i< 35; i++) {
			sum += (input_to_hidden1_weights[i][j] * inputarray[i]);
		}
		temparray[j] = sum;
	}

	for (int i = 0; i < 35; i++) { // Tanh or ReLU activation
		temparray[i] = tanh_activation(temparray[i]);
		//temparray[i] = relu_activation(temparray[i]);
	}

	for (int i = 0; i < 35; i++) { // make input array for next layer
		inputarray[i] = temparray[i];
	}

	for (int j = 0; j < 26; j++) { // Dot product for hidden to output
		sum = 0;
		for (int i = 0; i < 35; i++) {
			sum += (hidden2_to_output_weights[i][j] * inputarray[i]);
		}
		temparray_26[j] = sum;
	}

	for (int i = 0; i < 26; i++) { // Logistic sigmoid activation
		temparray_26[i] = logistic_sigmoid_activation(temparray_26[i]);
	}


	for (int i = 0; i < 26; i++) { // make input array for next epoch
		outputarray[i] = temparray_26[i];
	}

	if (print == true) { // If we want to print out the output
		cout << (char)(index + 65) << ": " << outputarray[index];
		cout << "\n";
	}

	if (printmax == true) { // If we are performing a noise test
		float max = 0.0f;
		maxindex = 0;
		for (int i = 0; i < 26; i++) {
			if (outputarray[i] > max) {
				max = outputarray[i];
				maxindex = i;
			}
		}
	}

	/*Determining loss*/
	float loss = 0.0f;
	for (int i = 0; i < 26; i++) {
		loss += (1.0f / 2.0f) * (pow(outputarray[i] - out.at(i), 2));
	}

	if (loss > maxloss && printloss) {
		maxloss = loss;
		cout << "Max Loss: " << maxloss << endl;
	}

	else if (loss > maxloss) {
		maxloss = loss;
	}
	else if (printloss) {
		cout << "Accuracy: " << maxloss - loss << endl;
	}
	/******************************** BACK PROPAGATION PHASE **********************************/

	// Derivative of logistic sigmoid activation
	for (int i = 0; i < 26; i++) {
		deltas_26[i] = sigmoid_prime(outputarray[i]) * (out.at(i) - outputarray[i]);
	}

	for (int i = 0; i < 35; i++) {
		deltas[i] = 0.0f;
		for (int j = 0; j < 26; j++) {
			deltas[i] += hidden2_to_output_weights[i][j] * deltas_26[j];
		}
	}

	// Derivative of tanh activation or ReLU activation
	for (int i = 0; i < 35; i++) {
		deltas[i] = deltas[i] * tanh_prime(inputarray[i]);
		//deltas[i] = deltas[i] * relu_prime(inputarray[i]);
	}

	// Adjusting weights for the next iteration
	for (int j = 0; j < 35; j++) {
		for (int i = 0; i < 35; i++) {
			input_to_hidden1_weights[i][j] = input_to_hidden1_weights[i][j] + (alpha * temparray[i] * deltas[j]);
		}
	}

	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 35; i++) {
			hidden2_to_output_weights[i][j] = hidden2_to_output_weights[i][j] + (alpha * inputarray[i] * deltas_26[j]);
		}
	}
}

bool noise_test(vector<float> in, vector<float> out, int correct_index, int flip_count) {
	vector<int> indices_to_flip; // this vector is of size flip_count-determines which bits to flip from 0 to 1 or vice versa
	indices_to_flip.push_back(rand() % 35);
	for (int i = 1; i < flip_count; i++) {
		int randindex = rand() % 35;
		while (find(indices_to_flip.begin(), indices_to_flip.end(), randindex) != indices_to_flip.end()) { // make sure we flip different bits!
			randindex = rand() % 35;
		}
		indices_to_flip.push_back(randindex);
	}


	for (int i = 0; i < indices_to_flip.size(); i++) {
		if (in.at(indices_to_flip.at(i)) == 0) {
			in.at(indices_to_flip.at(i)) = 1.0f;
		}
		else in.at(indices_to_flip.at(i)) = 0.0f;
	}

	forward_feed(in, out, 0, false, true, false, correct_index);

	return maxindex == correct_index; // if true, keep flipping, otherwise stop flipping bits
}

vector<float> parse_keyboard_input(string s) {
	vector<float> properinput;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '0')
			properinput.push_back(0.0f);
		else if (s.at(i) == '1')
			properinput.push_back(1.0f);
	}
	return properinput;
}

int main() {
	srand(time(NULL));
	init(); // Initialize our weight matrices with random weights
	int epochs = 2000; // # of epochs
	float alpha = 0.1f; // learning rate
	
	// Training the neural network using back propagation algorithm from the book.

	cout << "Training network and printing loss." << endl;

	for (int e = 0; e < epochs; ++e) {
		for (int n = 0; n < 26; ++n) {
		/* This if block tells the back propagation algorithm to print the calculated loss every 100th epoch
		where an epoch is running back propagation one time on all 26 letters. */
			if (e % 100 == 0 || e == 0) {
				back_propagation(input.at(n), desiredoutput.at(n), alpha, false, false, true, 0);
				}
			else back_propagation(input.at(n), desiredoutput.at(n), alpha, false, false, false, 0);
		}
	}

	cout << endl << endl << endl;

	cout << "Testing all letters: \n" << endl;

	for (int i = 0; i < 26; i++) {
		forward_feed(input.at(i), desiredoutput.at(i), 0, true, true, false, i);
	}

	cout << "Noise test (maximum # of bit flips): \n" << endl;

	/* Testing noise resistance by doing an increasing number of random bit flips until
	the network fails to guess the correct letter. */
	for (int k = 0; k < 1000; k++) {
		for (int i = 0; i < 26; i++) {
			int count = 1;
			bool is_correct = true;
			do {
				is_correct = noise_test(input.at(i), desiredoutput.at(i), i, count);
				count++;
			} while (is_correct && count < 36);
			if (count - 1 > noise_immunity_results.at(i)) {
				noise_immunity_results.at(i) = count - 1;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << char(65 + i) << ": " << noise_immunity_results.at(i) << endl;
	}
	cout << "Please input a string of 35 1s and 0s: ";
	string s;
	getline(cin, s);
	vector<float> parsedinput = parse_keyboard_input(s);
	cout << "What character should the network guess (uppercase)? ";
	char c;
	cin >> c;

	cout << endl << endl;

	int n = int(c) - 65;
	
	forward_feed(parsedinput, desiredoutput.at(n), 0, true, true, false, n);
	if (maxindex == n) {
		cout << "Correct guess!" << endl;
	}
	else cout << "Incorrect guess." << endl;
	//system("pause");
	return 0;
}


