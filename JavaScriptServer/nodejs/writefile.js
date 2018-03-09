const fs = require('fs');

fs.open('myfile', 'wx', (err, fd) => {
    if(err) {
        if(err.code === 'EEXISTS'){
            console.error('fila exista');
            return;
        }
        throw err;
    }
    writeMyData(fd);
})