


void function(int a, int b)
{
  const char* quot = "Line without /*comment*/";
  const char* qout2 = "Line //without comment";
  
  printf("Hello, /* my friend %s */ !"/* my friend %s */, quot, quot2);
}
