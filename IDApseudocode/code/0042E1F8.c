__sighandler_t unregister_signal()
{
  signal(15, (__sighandler_t)1);
  signal(2, (__sighandler_t)1);
  signal(1, (__sighandler_t)1);
  signal(3, (__sighandler_t)1);
  signal(13, (__sighandler_t)1);
  signal(11, (__sighandler_t)1);
  signal(18, (__sighandler_t)1);
  signal(17, (__sighandler_t)1);
  return signal(20, (__sighandler_t)1);
}

