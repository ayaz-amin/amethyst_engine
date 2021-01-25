function OnStart()
    x = 10
end

function OnUpdate(delta_time)
    PrintText(x, 300, 100, 20)
    PrintText(delta_time, 300, 200, 20)
end