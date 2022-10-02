-- table Labourses

create table
    labourers{id int NOT NULL,
    name VARCHAR(20) NOT NULL,
    previous_balance int NOT NULL,
}
create table
    dailyHours{labourer_id int NOT NULL,
    entry_time VARCHAR(20) NOT NULL,
    exit_time VARCHAR(20) NOT NULL,
    FOREIGN KEY (labourer_id) REFERENCES labourers(id)}-- query list of employees and amount (previous_balance + (exit_time - entry_time)*30) order by name
select
    labourers.name as lab,
    labourers.previous_balance + (
        dailyHours.exit_time - dailyHours.entry_time
    ) * 30 as amount
where
    labourers.id = dailyHours.labourer_id
order by labourers.name