var addon = require('bindings')('addon');

var aiBot = new addon.AIBot(10);
console.log('Keys available:');

for (var key in aiBot) {
    console.log(key);
}
console.log(aiBot.printTime());
console.log(aiBot.plusOne()); // 11
console.log(aiBot.plusOne()); // 12
console.log(aiBot.plusOne()); // 13

console.log(aiBot.multiply().value()); // 13
console.log(aiBot.multiply(10).value()); // 130

var newaiBot = aiBot.multiply(-1);
console.log(newaiBot.value()); // -13
console.log(aiBot === newaiBot); // false