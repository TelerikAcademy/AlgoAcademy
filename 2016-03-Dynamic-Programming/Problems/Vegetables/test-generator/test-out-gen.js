'use strict';

const fs = require('fs'),
    spawn = require('child_process').spawn,
    dir = './Tests';

module.exports = function(dir, binaryName) {
    fs.readdirSync(dir)
        .filter(x => x.indexOf('in') > -1)
        .forEach(function(name, index) {

            let solution = spawn(binaryName);
            
            let ws = fs.createWriteStream(`${dir}/${name.replace('in', 'out')}`);
            
            solution.stdout.pipe(ws);
            solution.stderr.on('data', data => console.log(data.toString()));

            let rs = fs.createReadStream(`${dir}/${name}`);

            rs.pipe(solution.stdin);

            solution.on('close', function(code) {
                ws.end();
                console.log(`test ${index}(output) ready`);
                if(code !== 0) {
                    console.log(`Child process ${index} exited with code ${code}`);
                }
            });
        });
};