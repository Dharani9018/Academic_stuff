pid_t fork() {

    // 1. Kernel creates a new process structure
    child = create_new_process();

    if (child == NULL)
        return -1;   // fork failed (only parent exists)

    // 2. Copy parent's execution context
    child.memory      = copy_on_write(parent.memory);
    child.registers   = parent.registers;
    child.stack       = parent.stack;
    child.program_ctr = parent.program_ctr + 1;

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

