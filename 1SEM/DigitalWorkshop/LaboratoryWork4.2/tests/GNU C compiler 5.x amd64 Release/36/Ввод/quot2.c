


void function(int a, int b)
{
  const char* quot = "Line \" without /*com \" ment*/";
  const char* qout2 = "Line //without \" // comment";
  const char* qout3 = "Line //without \" // com \" ment";
  
  printf("Hello, /* my friend %s */ !"/* my friend %s */, quot, quot2);
}
