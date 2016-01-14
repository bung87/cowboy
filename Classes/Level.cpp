const float kUpdateInterval = 1.0f / 60.0f;
const double kSecondsPerUpdate = 0.1;

double getCurrentTimeInSeconds()
{
  static struct timeval currentTime;
  gettimeofday(&currentTime, nullptr);
  return (currentTime.tv_sec) + (currentTime.tv_usec / 1000000.0);
}

Level::Level()
{
  // initialize variables, load the tmx, create the objects, etc...

  // schedule the update
  this->schedule(schedule_selector(Level::update), kUpdateInterval);
}

void Level::update(float dt)
{
  // get current time double
  currentTime = getCurrentTimeInSeconds();
  if (!lastTickTime)
    lastTickTime = currentTime;

  // determine the amount of time elapsed since our last update
  double frameTime = currentTime - lastTickTime;
  accumulator += frameTime;

  // update the world with the same seconds per update
  while (accumulator > kSecondsPerUpdate)
  {
    accumulator -= kSecondsPerUpdate;

    // perform a single step of the physics simulation
    world->Step(kSecondsPerUpdate, 8, 1);
  }
  lastTickTime = currentTime;
}
