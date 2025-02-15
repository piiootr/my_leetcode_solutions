/*
0016
https://leetcode.com/problems/3sum-closest/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    #define SUMS3(A, B, C) (nums[A] + nums[B] + nums[C])
    #define DIST_TARGET(A) (abs(target - A))
    int i, j, k;
    int h, s;

    /* sort array */
    h = 0;
    while(h < numsSize - 1) {
        if(nums[h] > nums[h + 1]) {
            nums[h] ^= nums[h + 1];
            nums[h + 1] ^= nums[h];
            nums[h] ^= nums[h + 1];

            if(h > 0) h--;
            else h++;
        } else h++;
    }

    /* find solutions */
    s = SUMS3(0, 1, 2);
    for(i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while(i < j && j < k) {

            h = SUMS3(i, j, k);
            if(DIST_TARGET(h) < DIST_TARGET(s)) {
                s = h;
            }
            if(h > target) k--;
            else j++;
        }
    }

    return s;
    #undef SUMS3
    #undef DIST_TARGET
}


int main(int argc, char** argv)
{
    //int arr[] = {-1,2,1,-4};
    //int t = 1; // s: 2
    //int arr[] = {0,0,0};
    //int t = 1; // s: 0
    //int arr[] = {4,0,5,-5,3,3,0,-4,-5};
    //int t = -2; // s: -2
    //int arr[] = {1,1,1,0};
    //int t = 100; // s: 3
    //int arr[] = {-4,2,2,3,3,3};
    //int t = 0; // s: 0
    //int arr[] = {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1};
    //int t = -14; // s: -15
    //int arr[] = {-86,8,0,-79,-23,88,-26,-17,41,70,1,29,3,-52,-30,-31,14,42,4,-52,-77,-39,91,-13,98,41,-16,-8,91,54,50,1,-22,45,30,20,-36,-41,-48,-25,-3,76,69,-38,78,-45,-75,-57,55,-23,65,-23,69,60,85,-95,84,-73,-21,43,35,58,66,6,-49,38,-5,46,-24,23,-23,63,55,-91,80,-73,-53,24,-77,-5,-93,4,2,-71,23,2,-44,-19,33,73,9,-94,41,81,-14,43,27,3,-65,-89,0,-100,-89,-76,95,0,-60,65,-77,85,-29,98,-8,18,41,-93,-64,51,-77,-39,-75,-6,-65,0,-15,66,80,67,-96,26,-57,-43,-76,72,20,-55,-83,95,-65,22,-47,-90,-83,13,6,81,-23,-50,-17,17,100,99,66,-62,-21,76,37,60,-88,64,78,-90,67,-65,-62,55,-87,-75,-79,14,87,-100,-87,9,-98,0,-83,7,29,33,-87,-50,6,-57,28,17,26,4};
    //int t = 136; // s: 136
    int arr[] = {13,252,-87,-431,-148,387,-290,572,-311,-721,222,673,538,919,483,-128,-518,7,-36,-840,233,-184,-541,522,-162,127,-935,-397,761,903,-217,543,906,-503,-826,-342,599,-726,960,-235,436,-91,-511,-793,-658,-143,-524,-609,-728,-734,273,-19,-10,630,-294,-453,149,-581,-405,984,154,-968,623,-631,384,-825,308,779,-7,617,221,394,151,-282,472,332,-5,-509,611,-116,113,672,-497,-182,307,-592,925,766,-62,237,-8,789,318,-314,-792,-632,-781,375,939,-304,-149,544,-742,663,484,802,616,501,-269,-458,-763,-950,-390,-816,683,-219,381,478,-129,602,-931,128,502,508,-565,-243,-695,-943,-987,-692,346,-13,-225,-740,-441,-112,658,855,-531,542,839,795,-664,404,-844,-164,-709,167,953,-941,-848,211,-75,792,-208,569,-647,-714,-76,-603,-852,-665,-897,-627,123,-177,-35,-519,-241,-711,-74,420,-2,-101,715,708,256,-307,466,-602,-636,990,857,70,590,-4,610,-151,196,-981,385,-689,-617,827,360,-959,-289,620,933,-522,597,-667,-882,524,181,-854,275,-600,453,-942,134};
    int t = -2805; // s: -2805

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("t: %2d || s: %2d\n", t, threeSumClosest(&arr[0], arr_size, t));

    return 0;
}