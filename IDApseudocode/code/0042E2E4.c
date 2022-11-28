__sighandler_t register_signal()
{
  struct sigaction v1; // [sp+18h] [-90h] BYREF

  v1.sa_handler = (__sighandler_t)1;
  sigaction(13, &v1, 0);
  signal(2, (__sighandler_t)sub_42CE20);
  signal(9, (__sighandler_t)sub_42CE20);
  signal(15, (__sighandler_t)sub_42CE20);
  signal(11, (__sighandler_t)sub_42C3EC);
  signal(18, (__sighandler_t)sub_42FB54);
  return signal(17, jhl_httpd_just_debug_signal);
}

