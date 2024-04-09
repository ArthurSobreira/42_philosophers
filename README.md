<div align="center"><h1>Philosophers [125 / 100]</h1></div>

<div align="center">
   <a href="https://github.com/ArthurSobreira/42_push_swap" target="_blank">
      <img height=170 src="https://github.com/ayogun/42-project-badges/blob/main/badges/philosophersm.png" hspace = "10">
   </a>
</div>

## Summary

> <i>The ninth project in the 42sp fundamentals track, <strong>Philosophers</strong>, is about to solve the the <strong>Dining Philosophers Problem</strong>, </i>
> <i>a famous problem in computer science used to illustrate common issues in concurrent programming. The main objective of this project is to introduce the use </i>
> <i>of <strong>Threads</strong>, <strong>Mutexes</strong>, <strong>Semaphores</strong> and <strong>Forks</strong>.</i>

<br>

## Run the Program

* Make sure you clone the repository with the following command:

```bash
$> git clone git@github.com:ArthurSobreira/42_philosophers.git
```

* Once cloned, to compile the program, use the following commands:

```bash
$> make / make bonus
```

<br>

## The Project

* To run either the mandatory or bonus part of the program, just call <code>./philo</code> or <code>./philo_bonus</code> passing the following arguments:

```bash
$> ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [times_each_philosopher_must_eat] (optional)
```

* The program should display a log in the terminal with some information about each philo:

```bash
timestamp_in_ms X 🍽 has taken a fork
timestamp_in_ms X 🍝 is eating
timestamp_in_ms X 💤 is sleeping
timestamp_in_ms X 💡 is thinking
timestamp_in_ms X 💀 died
```
