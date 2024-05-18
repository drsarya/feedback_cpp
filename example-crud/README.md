# Example-CRUD  
 
## Overview

This project is using the following oatpp modules:

- [oatpp](https://github.com/oatpp/oatpp)
- [oatpp-swagger](https://github.com/oatpp/oatpp-swagger)
- [oatpp-sqlite](https://github.com/oatpp/oatpp-sqlite)

### Project layout

```
|- CMakeLists.txt                        // projects CMakeLists.txt
|- sql/                                  // SQL migration scripts for SQLite database
|- src/
|   |
|   |- controller/                       // Folder containing REST Controllers (UserController)
|   |- db/                               // Folder containing the database client
|   |- dto/                              // DTOs are declared here
|   |- service/                          // Service business logic classes (UserService)
|   |- AppComponent.hpp                  // Service config
|   |- DatabaseComponent.hpp             // Database config
|   |- SwaggerComponent.hpp              // Swagger-UI config
|   |- App.cpp                           // main() is here
|
|- test/                                 // test folder
|- utility/install-oatpp-modules.sh      // utility script to install required oatpp-modules.
```

---

### Build and Run

#### Using CMake

##### Pre Requirements

- `oatpp`
- `oatpp-swagger`
- `oatpp-sqlite` with `-DOATPP_SQLITE_AMALGAMATION=ON` cmake flag.

**Note:** You may run `utility/install-oatpp-modules.sh` script to install required oatpp modules.

##### Build Project

```
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./crud-exe        # - run application.
```

#### In Docker

```
$ docker build -t example-crud .
$ docker run -p 8000:8000 -t example-crud
```

---

