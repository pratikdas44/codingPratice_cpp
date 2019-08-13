int arr[] = {4,0,2,1,3};int n=5;
   for (int i=0; i < n; i++)
        {arr[i] += (arr[arr[i]]%n)*n; cout << arr[i] << " ";}

    // Second Step: Divide all values by n
    for (int i=0; i<n; i++)
        arr[i] /= n;