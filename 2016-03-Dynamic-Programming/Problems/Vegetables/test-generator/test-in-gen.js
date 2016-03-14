'use strict';

const fs = require('fs'),
      newLine = '\r\n';

function range(start, length) {
    let nums = [];

    for (let i = 0; i < length; i += 1) {
        nums.push(start + i);
    }

    return nums;
}

function randInt(low, high) {
    return (Math.random() * (high - low) | 0) + low;
}

const maxN = 10000,
    maxV = 100,
    minV = 0,
    maxR = 1200,
    minR = 1,
    maxC = 1200,
    minC = 1;

function genTest(description) {
    let test = [[description.r1, description.c1]];

    for (let i = 0; i < description.r1; i += 1) {
        let line = range(0, description.c1).map(x => randInt(description.low, description.high));
        test.push(line);
    }

    test.push([description.r2, description.c2]);

    for (let i = 0; i < description.r2; i += 1) {
        let line = range(0, description.c2).map(x => randInt(description.low, description.high));
        test.push(line);
    }

    test.push([description.n]);
    return test.map(line => line.join(' '));
}

function writeTestToFile(dir, content, number, isZeroTest) {
    if (!fs.existsSync(dir)) {
        fs.mkdirSync(dir);
    }

    let n = (number <= 9 ? `00${number}` : `0${number}`);

    if (isZeroTest) {
        n = '000.' + n;
    }

    let stream = fs.createWriteStream(`${dir}/test.${n}.in.txt`);

    content.forEach(x => stream.write(x + newLine));

    stream.end();

    console.log(`test ${n}(input) ready`);
}

function Descr(n, getR) {
    return {
        r1: getR(),
        c1: getR(),
        r2: getR(),
        c2: getR(),
        low: minV,
        high: 10,
        n: n
    };
};

let descriptions = [
    {
        r1: minR,
        c1: minC,
        r2: minR,
        c2: minC,
        low: minV,
        high: maxV,
        n: maxN
    },
    {
        r1: 5,
        c1: 4,
        r2: 8,
        c2: 3,
        low: minV,
        high: 20,
        n: 1
    },
    {
        r1: 5,
        c1: 4,
        r2: 8,
        c2: 3,
        low: minV,
        high: 20,
        n: 2
    },
    {
        r1: 10,
        c1: 5,
        r2: 3,
        c2: 15,
        low: minV,
        high: 20,
        n: 10
    },
    {
        r1: 5,
        c1: 5,
        r2: 7,
        c2: 2,
        low: minV,
        high: maxV,
        n: 15
    },
    {
        r1: 30,
        c1: 35,
        r2: 50,
        c2: 25,
        low: minV,
        high: maxV,
        n: 11
    },
    {
        r1: 5,
        c1: 700,
        r2: 800,
        c2: 4,
        low: 75,
        high: maxV,
        n: 19
    },
    {
        r1: 400,
        c1: 400,
        r2: 350,
        c2: 650,
        low: minV,
        high: maxV,
        n: 15
    },
    {
        r1: 500,
        c1: 673,
        r2: 777,
        c2: 431,
        low: minV,
        high: 10,
        n: 7
    },
    {
        r1: maxR,
        c1: maxC,
        r2: maxR,
        c2: maxC,
        low: minV,
        high: 10,
        n: 7
    },
    {
        r1: maxR,
        c1: maxC,
        r2: maxR,
        c2: maxC,
        low: minV,
        high: 10,
        n: randInt(0.9 * maxN | 0, maxN)
    }
    ,
    {
        r1: maxR,
        c1: maxC,
        r2: maxR,
        c2: maxC,
        low: minV,
        high: 10,
        n: randInt(0.9 * maxN | 0, maxN)
    }
];

let metaDescriptions = [
    {
        count: 3,
        getN: () => randInt(100, 1000),
        getSize: () => randInt(600, 1000)
    },
    {
        count: 6,
        getN: () => randInt(500, 2000),
        getSize: () => randInt(50, 600)
    },
    {
        count: 5,
        getN: () => randInt(1000, 8000)
    },
    {
        count: 2,
        getN: () => randInt(8000, maxN)
    },
    {
        count: 2,
        getN: () => maxN
    }
];

let zeroTests = [
    [
        '3 3',
        '1 2 3',
        '1 4 5',
        '7 8 1',
        '2 2',
        '1 2',
        '3 4',
        '1'
    ],
    [
        '2 2',
        '0 2',
        '3 1',
        '2 3',
        '1 1 2',
        '2 0 1',
        '4'
    ]
];

module.exports = function(dir) {

    let i = 0,
        zeros = 0;

    zeroTests.forEach(x => writeTestToFile(dir, x, zeros++, true));

    descriptions.forEach(d => writeTestToFile(dir, genTest(d), i++));

    const defaultSize = () => randInt(maxR / 2, maxR);

    metaDescriptions.forEach(function(md) {
        range(0, md.count)
            .forEach(function(test) {
                let description = Descr(md.getN(), md.getSize || defaultSize);
                writeTestToFile(dir, genTest(description), i++);
            });
    });
};