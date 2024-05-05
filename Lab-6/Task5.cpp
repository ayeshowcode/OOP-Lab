/*
Task-05
Consider that You're working on Images to handle images in your graphics application. Each Image object contains a pointer to image data stored in memory. You are asked to create Image Class: The Image class represents an image with width, height, and image data as private. The data member represents the image data stored in memory. It's a pointer to a block of memory here the actual pixel values of the image are stored.

Create Constructor: Constructor that initializes the width, height, and data pointer. It dynamically allocates memory for the image data and copies the provided data. By copying the provided image data, the Image class creates an independent copy of the data. This means that modifications made to the original image data outside the class won't affect the internal representation of the image
within the Image object.

Create Copy constructor that creates a new Image object as a copy of another Image object. It allocates memory for the image data and copies the data from the original image.

Class must have Destructor that deallocates the memory allocated for the image data.

Create void display(): Displays the image data.

Create the updateData function: that takes original image data and updates those values which are 0 are less than 0 with any random value between the range of 1<=255
//Main function:
Create an Image object with dimensions 2x3 and initialize it with sample data.
Creates a copy of the original image.
Displays the data of both the original and copied images using the display() function.
After that call the updateData function and then call the display() function again to verify that changes are made in both original and copied data
*/
#include <iostream>
using namespace std;

class Image {
    int width, height;
    int* data;

public:
    // Constructor
    Image(int w, int h, int* d) : width(w), height(h) {
        data = new int[w * h];
        for(int i = 0; i < w * h; ++i) {
            data[i] = d[i];
        }
    }

    // Copy constructor
    Image(const Image& img) : width(img.width), height(img.height) {
        data = new int[width * height];
        for(int i = 0; i < width * height; ++i) {
            data[i] = img.data[i];
        }
    }
    // Destructor
    ~Image() {
        delete[] data;
    }

    // Display the image data
    void display() {
        for(int i = 0; i < width * height; i++) {
            cout << data[i] << " ";
            if ((i + 1) % width == 0) { // New line for each row
                cout << endl;
            }
        }
        cout << endl;
    }

    // Update the image data
    void updateData() {
        for(int i = 0; i < width * height; i++) {
            if(data[i] <= 0) {
                data[i] = 1 + (i % 255); // Update with a value between 1 and 255
            }
        }
    }
};

int main() {
    int data[] = {0, 1, 2, 3, 4, 5};
    Image img1(2, 3, data);
    Image img2 = img1;  // Copy the image

    cout << "Original image data: ";
    img1.display();

    cout << "Copied image data: ";
    img2.display();

    img1.updateData();
    img2.updateData();

    cout << "Updated original image data: ";
    img1.display();

    cout << "Updated copied image data: ";
    img2.display();

    return 0;
}