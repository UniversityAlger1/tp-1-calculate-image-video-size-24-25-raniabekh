#include <string.h>
#include "config/video.h"
#include<stdio.h>
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN

// Calculate the size of a single frame (3 bytes for RGB, 1 byte for grayscale)
    double sizeColorFrame = w * h * 3; // In bytes
    double sizeBWFrame = w * h;       // In bytes (1 byte for grayscale)

    // Calculate total frames for color and black-and-white sections
    int totalColorFrames = durationMovie * fps;
    int totalBWFrames = durationCredits * fps;

    // Total size in bytes
    double totalSizeInBytes = (sizeColorFrame * totalColorFrames) + (sizeBWFrame * totalBWFrames);

    // Convert the size to the desired unit
    if (strcmp(unit, "bt") == 0) {       // Bits
        return totalSizeInBytes / 8;
    } else if (strcmp(unit, "ko") == 0) { // Kilobytes
        return (totalSizeInBytes /8)/ 1024;
    } else if (strcmp(unit, "mo") == 0) { // Megabytes /// rtestttt
        return (((totalSizeInBytes /8)/ 1024) / 1024);
    } else if (strcmp(unit, "go") == 0) { // Gigabytes
        return ((((totalSizeInBytes /8)/ 1024 )/ 1024) / 1024);
    } else {
        printf("Invalid unit. Use 'bt' (bits), 'ko' (kilobytes), 'mo' (megabytes), or 'go' (gigabytes).\n");
        return -1; // Indicate an error
    }
}
