// index.js
const addon = require('./build/Release/hello.node'); // Caminho padrão onde o node-gyp coloca o binário

console.log('O addon nativo diz:', addon.hello()); // Chama a função hello exposta pelo addon

try {
    const os = require('os');
    console.log('Sistema operacional detectado:', os.platform());
} catch (e) {
    console.error('Não foi possível detectar o OS:', e.message);
}

console.log('Node.js version:', process.version);