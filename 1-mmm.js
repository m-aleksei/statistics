process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

function mean (k, arr) { // среднее
    var summ = 0;
    for (var i = 0; i < k; i++) {
        summ = summ + arr[i];
    }
    summ = (summ/k).toFixed(1); // формат 0.0
    return summ;
}

function median (k, arr) { // медиана
    var i, j;
    var d = 1; // число перестановок
    var se;  
    // bubble sort
    while (d > 0) { 
        d = 0;
        for (i = 1; i < k; i++) {
            if (arr[i-1] > arr[i]) {
                se = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = se;
                d = d + 1;
            }
        }
    }
    if (k % 2 == 0) {
        i = Math.floor((k-1)/2);
        j = Math.ceil(k/2);
        se = ((arr[i]+arr[j])/2).toFixed(1);
    } else {
        i = Math.floor((k-1)/2);
        se = (arr[i]).toFixed(1);
    }
    return se;
}

function mode (k, arr) { // мода
    var i,j;
    var a = new Array(); // number of equal elements
    var maxx; // max number
    var minn; // min element
    for (i = 0; i < k; i++) {
        a[i] = 0;
        for (j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                a[i] = a[i] + 1;
            }
        }
    }
    maxx = a[0];
    for (i = 1; i < k; i++) {
        if (a[i] > maxx) {
            maxx = a[i];
        }
    }
    minn = arr[k-1];
    for (i = 0; i < k; i++) {
        if (a[i] == maxx) {
            if (arr[i] < minn) {
                minn = arr[i];
            }
        }
    }
    
    return minn;
}

function main() {
    var n = parseInt(readLine());
    var c = new Array();
    c = readLine().split(' ');
    c = c.map(Number);
        
    process.stdout.write("" + mean(n,c) + "\n"); 
    process.stdout.write("" + median(n,c) + "\n"); 
    process.stdout.write("" + mode(n,c) + "\n"); 
    
}
