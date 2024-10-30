function updateEnemy() {
    const dx = player.x - enemy.x;
    const dy = player.y - enemy.y;
    const angle = Math.atan2(dy, dx);
    enemy.x += Math.cos(angle) * enemy.speed;
    enemy.y += Math.sin(angle) * enemy.speed;
}

function gameLoop() {
  update(); // تحديث مواقع اللاعب والمطارد
  draw(); // رسم اللعبة
  checkCollision(); // التحقق من التصادم
  requestAnimationFrame(gameLoop);
}
