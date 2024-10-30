const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d');

const player = {
    x: 10,
    y: 10,
    width: 20,
    height: 20,
	color: 'green',
	speed: 10,
	direction: 'left'
};

const enemy = {
    x: canvas.width - 30,
    y: canvas.height - 30,
    width: 20,
    height: 20,
	color: 'red',
	speed: 5
};

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.fillStyle = player.color;
    ctx.fillRect(player.x, player.y, player.width, player.height);
	ctx.fillStyle = enemy.color;
    ctx.fillRect(enemy.x, enemy.y, enemy.width, enemy.height);
}

document.onkeydown = function (e) {
	if (e.keyCode == 37) player.direction = 'right'
	if (e.keyCode == 39) player.direction = 'left'
	if (e.keyCode == 38) player.direction = 'up' 
	if (e.keyCode == 40) player.direction = 'down' 
};

function update() {
	if (player.direction == 'right')	player.x -= player.speed
	if (player.direction == 'left')		player.x += player.speed
	if (player.direction == 'up')		player.y -= player.speed
	if (player.direction == 'down')		player.y += player.speed

  const dx = player.x - enemy.x;
  const dy = player.y - enemy.y;
  const angle = Math.atan2(dy, dx);
  enemy.x += Math.cos(angle) * enemy.speed;
  enemy.y += Math.sin(angle) * enemy.speed;

  player.x = Math.max(0, Math.min(canvas.width  - player.width,  player.x));
  player.y = Math.max(0, Math.min(canvas.height - player.height, player.y));
  enemy.x  = Math.max(0, Math.min(canvas.width  - enemy.width,   enemy.x));
  enemy.y  = Math.max(0, Math.min(canvas.height - enemy.height,  enemy.y));
}

function checkCollision() {
  const left1 = player.x;
  const left2 = enemy.x;

  const right1 = player.x + player.width;
  const right2 = enemy.x + enemy.width;

  const top1 = player.y;
  const top2 = enemy.y;

  const bottom1 = player.y + player.height;
  const bottom2 = enemy.y + enemy.height;

  if (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2) {
    console.log("لقد حدث تصادم!");
  }
}

function gameLoop() {
    update();
    draw();
    checkCollision();
    requestAnimationFrame(gameLoop);
}
gameLoop();

