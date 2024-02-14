//note first read histoarea then come to this as the consepts are similar only


//here we are given with a binary matrix for which we need to find the max area if we look similarly this problem is similar to the histoarea one only diff is there it was 1d here it is 2d so we need to convert the given 2d matrix into 1d and that can be easily performed i.e take 1st row assume 0 1 1 0 now compute the area for each historgram store the max value now assume 2nd row was 1 1 1 1 => 1 2 2 1 this is got by adding the 2 rows again compute area and store the max value now assume if the 3rd row is 1 1 0 0 then the resulting historgram will be 1 2 0 0 again compute the same and return max area

