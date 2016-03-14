'use strict';

const dir = './Tests';

require('./test-in-gen')(dir);
require('./test-out-gen')(dir, 'solution.exe');

console.log('test generation successful');