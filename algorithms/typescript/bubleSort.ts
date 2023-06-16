import stringList from '../../data/data.json';
import stringText from '../../data/text.json';
const list: Number[] = [];

for (let i = 0; i < 20000; i++) {
    list.push(parseFloat((Math.random() * 100).toFixed(4)))
}

function bubbleSort(array: String[] | Number[]) {
    const startTime = performance.now();

    for (var i = 0; i < array.length; i++) {
        for (var j = 0; j < (array.length - i - 1); j++) {
            if (array[j] > array[j + 1]) {
                var aux = array[j]
                array[j] = array[j + 1]
                array[j + 1] = aux
            }
        }
    }

    const endTime = performance.now();

    const elapsedTime = (endTime - startTime) / 1000;

    const result = {
        "Tempo de execução (segundos)": parseFloat(elapsedTime.toFixed(6)),
    };

    console.log("Array ordenado pelo Bubble Sort: \n");
    console.table(array);
    console.table(result);
}

console.log("Array inicial: \n");
console.table(stringText);
bubbleSort(stringText);