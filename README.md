# Linux Semaphores CLI Utilities

Welcome to the Linux Semaphores CLI Utilities repository! Dive into the world of inter-process synchronization with this collection of command-line tools implemented in C. These utilities are designed to seamlessly create, manage, and operate on semaphores in the Linux operating system.

## Why Semaphores in Linux?

Harness the power of semaphores, a fundamental synchronization mechanism in Linux, with this set of utilities. Key features include:

- **Semaphore Creation:** Generate semaphores using `semget()`, specifying options like `IPC_CREAT` for creating a new semaphore set and `IPC_EXCL` for exclusive creation..

- **Key Generation:** Leverage the `key_t` parameter, generated with `IPC_PRIVATE` or `ftok()`, as a unique identifier for your semaphore set.

- **Semaphore Operations:** Perform semaphore operations such as wait and signal using `semop()`, facilitating coordinated access to shared resources.

- **Semaphore Information:** Retrieve information about existing semaphore sets, including key, mode, and values.

## Repository Highlights:

Explore a carefully crafted collection of C-based command-line utilities, each showcasing different aspects of semaphore manipulation and functionality. From creating semaphore sets to performing operations, these programs serve as your comprehensive guide to mastering Linux semaphores.

## Getting Started:

Clone this repository to your local environment and delve into the intuitive CLI utilities. Utilize the provided compilation commands to seamlessly run the programs, unlocking the potential of inter-process synchronization through semaphores.

## Repository Contents:

- **sem_create.c:** Command-line utility illustrating the creation of a new semaphore set using semget().
- **sem_op.c:** CLI tool demonstrating semaphore operations like wait and signal using semop().
- **sem_get_info.c:** Command-line program showcasing how to retrieve information about existing semaphore sets.
- **sem_set_all.c:** Command-line program showcasing how to set initial information in created semaphore sets.

## Contributions:

Feel free to contribute to this repository by adding your own CLI utilities or enhancing the existing ones. Let's collaboratively build a comprehensive resource for mastering Linux semaphores through elegant and efficient command-line tools.
