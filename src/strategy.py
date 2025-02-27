# ...existing code...

def create_formation():
    formation_path = './formations-dt/goalie-catch-our.conf'
    if not os.path.exists(formation_path):
        print(f"Formation file not found: {formation_path}")
        sample_coach_info = {
            'name': 'Sample Coach',
            'experience': 5,
            'strategy': 'defensive'
        }
        print(f"Using sample coach info: {sample_coach_info}")
        return None
    # ...existing code to create formation...

def find_best_agent_to_pass(ball_position, agents):
    best_agent = None
    best_score = float('-inf')
    
    for agent in agents:
        score = evaluate_agent(ball_position, agent)
        if score > best_score:
            best_score = score
            best_agent = agent
            
    return best_agent

def evaluate_agent(ball_position, agent):
    # Example evaluation function, you can customize this
    distance_to_goal = calculate_distance(agent.position, goal_position)
    distance_to_ball = calculate_distance(agent.position, ball_position)
    score = -distance_to_goal + distance_to_ball
    return score

def calculate_distance(pos1, pos2):
    return ((pos1[0] - pos2[0]) ** 2 + (pos1[1] - pos2[1]) ** 2) ** 0.5

def create_formation():
    formation_path = './formations-dt/goalie-catch-our.conf'
    if not os.path.exists(formation_path):
        print(f"Formation file not found: {formation_path}")
        return None
    # ...existing code to create formation...

    ball_position = get_ball_position()
    agents = get_all_agents()
    best_agent = find_best_agent_to_pass(ball_position, agents)
    
    if best_agent:
        print(f"Best agent to pass the ball: {best_agent}")
    else:
        print("No suitable agent found to pass the ball.")
