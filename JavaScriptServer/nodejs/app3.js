//EVENTS

const EventEmitter = require('events');

const emitter = new EventEmitter();

emitter.on('mesajul_emis', (arg) => {
    console.log('listener called', arg);
});

emitter.emit('mesajul_emis', {id: 1,url: 'http://'});

