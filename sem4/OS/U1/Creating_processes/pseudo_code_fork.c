pid_t fork() {

    // 1. Kernel creates a new process structure
    child = create_new_process();

    if (child == NULL)
        return -1;   // fork failed (only parent exists)

    // 2. Copy parent's execution context
<<<<<<< HEAD
    child.memory      = copy_on_write(parent.memory); //only user_space
    child.registers   = parent.registers;
    child.stack       = parent.stack;
    child.program_ctr = parent.program_ctr + 1;
    //kernel objects are not copied, they're shared between parent and child
    //Kernel Space (shared)
/*
    File descriptor table entries

    File objects

    Pipe object

    Pipe buffer
*/
=======
    child.memory      = copy_on_write(parent.memory);
    child.registers   = parent.registers;
    child.stack       = parent.stack;
    child.program_ctr = parent.program_ctr + 1;
>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42

    // 3. Assign process IDs
    child.pid  = new_pid();
    child.ppid = parent.pid;

    // 4. Set return values DIFFERENTLY
    parent.return_value = child.pid;  // > 0
    child.return_value  = 0;

    // 5. Make both runnable
    scheduler.enqueue(parent);
    scheduler.enqueue(child);

    // 6. Return twice
    return parent.return_value OR child.return_value;
}

