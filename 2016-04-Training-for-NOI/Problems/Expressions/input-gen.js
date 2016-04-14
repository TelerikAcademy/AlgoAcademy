'use strict';
const randFloat = (low, high) => (Math.random() * (high - low)) + low,
    randBool = (chance) => Math.random() < chance,
    randSign = ((chance) => randBool(chance) ? -1 : 1),
    randInt = (low, high) => randFloat(low, high) | 0;
function range(start, count) {
    const res = [];
    for (let i = start; i < start + count; i += 1) { res.push(i); }
    return res;
}

let testCount = 20,
    zeroTests = [
        '~44*2',
        '5+4*|~3|',
        '5+4/2*3-3',
        '8>2',
        '1<10',
        '1<10/2+2^5-|-20|',
        '5^2*2',
        '3^3^2',
        '3^(4/|-2|)',
        '2<30+10000',
        '(2<30+10000)/16',
    ].map(x => [x]),
    tests = [];

const binaryOperators = ['^', '+', '-', '*', '/'];

let only = {
    sum: function() {
        let test = [];

        let operands = range(20, 1000).map(x => randInt(0, 20));

        test.push(operands.reduce((m, c) => m + (randBool(0.5) ? '+' : '-') + c, '').substr(1));
        test.push(operands.reduce((m, c) => m + (randBool(0.5) ? '+' : '-') + c, '').substr(1));

        return test;
    },
    multiplication: function() {
        let test = [];

        let operands = range(20, 1000).map(x => randInt(2, 20));

        test.push(operands.reduce((m, c) => m + (randBool(0.5) ? '*' : '/') + c, '').substr(1));
        test.push(operands.reduce((m, c) => m + (randBool(0.5) ? '*' : '/') + c, '').substr(1));

        return test;
    },
    bitwise: () => ['3<2<2<2>6', '2<20>5<1>3<2>4<5>6', '~20', '~9<10>1'],
    abs: () => ['|-5|', '|12312|'],
    power: () => ['17^3', '9^5', range(1, 40).map(x => randInt(2, 10)).join('^'), range(1, 40).map(x => randInt(2, 10)).join('^')]
};

let noBrackets = [];

for (let i = 0; i < 5; i += 1) {

    let test = range(0, 30).map(x => randInt(10, 20)).reduce((m, c) => m + (binaryOperators[randInt(0, binaryOperators.length)]) + c, '').substr(1);

    noBrackets.push(test);
}

let performanceNoBrackets = [

    range(0, 2000).map(x => randInt(0, 2000)).reduce((m, c) => m + (binaryOperators[randInt(0, binaryOperators.length)]) + c, '').substr(1),
    range(0, 2000).map(x => randInt(0, 2000)).reduce((m, c) => m + (binaryOperators[randInt(0, binaryOperators.length)]) + c, '').substr(1),
    '2^10000000',
    new Array(1000).join('99').split('').join('^')
];

let precedence = [
    '4*(3+5)-(~18*2+4)-|78*(-2)|',
    '4*(3+5)-10',
    '4/2*(1+1)/2',
    '1+3441/3<3*1',
    '~5*14+44*(-2)',
    '~(5*14)+44*(-2)',
    '~(5*14)^10+15',
    '10^3*4',
    '3*10^4',
    '10^3*4^5^1*3^0',
    '~(10*4/(3+|-1|)^(4-1)-3)+4^|~2|',
    '|4-5*20^3-33|*0',
    '|4-5*20^3-33|*(-1)',
    '10^(~(-22))',
    '20^((4+5+6*7+8-|~2|))*(-1)',
    '20*(4+5*(10+11*(3<2/2)+7^(3*4-10)+44<2))',
    '20/4+5*(10+11*(3-2/2)+7^(3*4-10))',
    '23<(4+5-6)<(3^(1<1))',
    '2*(-15)^|~2|*2'
];

let borderCases = [
    '|||-5|||',
    '~|||-5|||',
    '~(~(~(~(19))))',
    '(-1)*(-2)',
    '|4|^|-3|',
    '(20^3+19191*919)^(1>1)',
    '|2|<|-19|',
    '~0',
    '0^123',
    '19732',
];

let template = '(!)+(@)^|@|-(!)+|!|*(+(!))-(!<(!>!)/(@<1))';
let bracketsPerformance = range(0, 5).map(function(index) {
    template.replace()
    let nested = template.replace(new RegExp('\!', 'g'), precedence[randInt(0, precedence.length)]);
    let result = nested.replace(new RegExp('\@', 'g'), randInt(1, 5));

    return result;
});

tests = noBrackets.concat(borderCases, precedence, bracketsPerformance, performanceNoBrackets, only.abs(), only.bitwise(), only.multiplication(), only.power(), only.sum()).map(x => [x]);
console.log(tests);

module.exports = {
    getZeroTests: () => zeroTests.slice(),
    getTests: () => tests.slice()
}