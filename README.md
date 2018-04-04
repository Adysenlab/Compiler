# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

* Quick summary
    this is the basic version of a full fledged language that adysenlab vevo is required to produce my the offset of summer 2018 
* Version
    current at beta :: 0.001.0 [Refer to license ]
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
    A test language that you can play with have fun and research on. Do return back to us with suggestions and we would be happy for the help and maybe meet for coffee.
 
* Configuration
    the set of files can be built by cmake - makefile generator for the project source code 
select the build location of the source codes and try command 
* Dependencies
    c++ language compiler and cmake build generator but we are gearing towards LLVM code generation in the near future
* Database configuration
    none as of now and we are planning for a dedicative storage referal engine 
* How to run tests
    currently not added
* Deployment instructions

### cmake ..
this would result in the makefile which can be built using 

### make 
there is also configuration added for debian packaging support 

### cpack --config CPackConfig.cmake
this would generate the debian installers for binary distribution

### cpack --config CPackSourceConfig.cmake
this would build source source distributions with various compression levels
### Contribution guidelines ###

* Writing tests
    currently in development please push in tests for this language 
* Code review
    would  be generous to add to the mailing list of the future developments please contribute 
* Other guidelines
please don't spam we hate putting you in blocking lists 
### Who do I talk to? ###

* Repo owner or admin mail at adysenlab@gmail.com
* Other community or team contact [ slack channel comming up ]