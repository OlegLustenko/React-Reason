const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('hi!\r\n', answer => {
  console.log(answer);

  rl.question('ok\r\n', answer2 => {
    console.log(answer2);
    rl.close();
  });
});
